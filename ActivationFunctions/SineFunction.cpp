#include "SineFunction.h"

DataType SineFunction::compute(DataType x) {
    return std::sin(degreesToRadians(x));
}

DataType SineFunction::computeDervative(DataType x) {
    return std::cos(degreesToRadians(x));
}

DataType SineFunction::degreesToRadians(DataType x) {
    return (x);
}

ActivationFunction *SineFunction::clone() {
    return new SineFunction();
}
