//
// Created by Michał Gutowski on 21.04.15.
//

#include "LinearFunction.h"

DataType LinearFunction::compute(DataType x) {
    return x;
}

DataType LinearFunction::computeDervative(DataType x) {
    return 1;
}

ActivationFunction *LinearFunction::clone() {
    return new LinearFunction();
}
