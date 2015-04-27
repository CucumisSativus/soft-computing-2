//
// Created by Michał Gutowski on 21.04.15.
//

#ifndef LAYERPERCEPTRON_ACTIVATIONFUNCTION_H
#define LAYERPERCEPTRON_ACTIVATIONFUNCTION_H
#include "../Defines.h"

class ActivationFunction{
public:
    virtual DataType compute(DataType x) = 0;
    virtual DataType computeDervative(DataType x) =0;
    virtual ActivationFunction * clone() =0;
};
#endif //3LAYERPERCEPTRON_ACTIVATIONFUNCTION_H
