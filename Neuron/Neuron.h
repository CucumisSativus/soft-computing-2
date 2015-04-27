//
// Created by Michał Gutowski on 21.04.15.
//

#ifndef LAYERPERCEPTRON_NEURON_H
#define LAYERPERCEPTRON_NEURON_H

#include <stdexcept>
#include "../ActivationFunctions/ActivationFunction.h"
#include "../Defines.h"
#include "NeuronConfiguration.h"

class Neuron {
public:
    Neuron(ActivationFunction *func, int inputNumber, DataType defaultWeight = 1.0, DataType learningRate = 0.1);
    Neuron(const NeuronConfiguration & configuration);
    DataType output(DataVector const &inputs) const;
    DataVector train(DataVector const &inputs, DataType const &desiredOutput);
private:
    void inline checkInputNumber(DataVector const &inputs) const;
    DataType inline computeH(DataType x);
    ActivationFunction  * function;
    DataVector inputWeights;
    DataType learningRate;
};
#endif //3LAYERPERCEPTRON_NEURON_H
