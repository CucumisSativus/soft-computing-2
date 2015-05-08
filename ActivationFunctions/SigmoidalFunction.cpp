//
// Created by Michał Gutowski on 07.05.15.
//

#include "SigmoidalFunction.h"

ActivationFunction *SigmoidalFunction::clone() {
    return new SigmoidalFunction();
}

DataType SigmoidalFunction::computeDervative(DataType x) {
    return std::exp(x)/std::pow(std::exp(x) +1, 2);
}

DataType SigmoidalFunction::compute(DataType x) {
    return 1/(1+ std::exp(-x));
}
