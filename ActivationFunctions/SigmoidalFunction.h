//
// Created by Michał Gutowski on 07.05.15.
//

#ifndef LAYERPERCEPTRON_SIGMOIDALFUNCTION_H
#define LAYERPERCEPTRON_SIGMOIDALFUNCTION_H

#include "ActivationFunction.h"
#include <cmath>

class SigmoidalFunction : public ActivationFunction{

public:
    virtual DataType compute(DataType x);

    virtual DataType computeDervative(DataType x);

    virtual ActivationFunction *clone();
};


#endif //3LAYERPERCEPTRON_SIGMOIDALFUNCTION_H
