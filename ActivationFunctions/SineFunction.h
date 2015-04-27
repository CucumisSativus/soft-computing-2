//
// Created by Michał Gutowski on 27.04.15.
//

#ifndef LAYERPERCEPTRON_SINEFUNCTION_H
#define LAYERPERCEPTRON_SINEFUNCTION_H

#include <cmath>
#include "ActivationFunction.h"


class SineFunction : public ActivationFunction{

public:
    virtual DataType computeDervative(DataType x);

    virtual DataType compute(DataType x);

private:
    DataType inline degreesToRadians(DataType x);

public:
    virtual ActivationFunction *clone();
};


#endif //3LAYERPERCEPTRON_SINEFUNCTION_H
