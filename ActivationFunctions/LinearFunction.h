//
// Created by Michał Gutowski on 21.04.15.
//

#ifndef LAYERPERCEPTRON_LINEARFUNCTION_H
#define LAYERPERCEPTRON_LINEARFUNCTION_H

#include "../Defines.h"
#include "ActivationFunction.h"

class LinearFunction : public ActivationFunction{

public:
    virtual DataType computeDervative(DataType x);

    virtual ActivationFunction *clone();

    virtual DataType compute(DataType x);
};


#endif //3LAYERPERCEPTRON_LINEARFUNCTION_H
