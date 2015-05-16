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
    Neuron(ActivationFunction *func, int inputNumber, DataType defaultWeight, DataType learningRate, bool biased);
    Neuron(const NeuronConfiguration & configuration);
    DataType output(DataVector const &inputs) const;
    DataVector train(DataVector const &inputs, DataType const &desiredOutput);
    DataType weightAt(unsigned long index);
    void updateWights(DataVector inputs, DataType error);
private:
    void inline checkInputNumber(DataVector const &inputs) const;
    DataType inline computeH(DataType x);
    ActivationFunction  * function;
    DataVector inputWeights;
    DataType learningRate;
    bool biased;

    DataType computeWeightedSum(const DataVector &inputs) const;
};
#endif //3LAYERPERCEPTRON_NEURON_H
