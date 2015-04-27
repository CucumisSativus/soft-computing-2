//
// Created by Michał Gutowski on 21.04.15.
//

#include "Neuron.h"

Neuron::Neuron(ActivationFunction *func, int inputNumber, DataType defaultWeight, DataType learningRate)
        : function(func), inputWeights(inputNumber, defaultWeight), learningRate(learningRate) {

}

Neuron::Neuron(const NeuronConfiguration &configuration)
        : function(configuration.getFunction()),
          inputWeights(configuration.getInputNumber(), configuration.getNeuronInitialWeights()),
          learningRate(configuration.getLearningRate()) {

}

DataType Neuron::output(DataVector const &inputs) const {
    checkInputNumber(inputs);
    DataType weightedSum = 0;
    for (unsigned long i = 0; i < inputs.size(); ++i) {
        weightedSum += inputs[i] * inputWeights[i];
    }
    return function->compute(weightedSum);
}

DataVector Neuron::train(DataVector const &inputs, DataType const &desiredOutput) {
    checkInputNumber(inputs);
    DataVector deltas(inputs.size(), 0);
    for (unsigned long i = 0; i < inputs.size(); ++i) {
        DataType outputError = desiredOutput - output(inputs);
        DataType x = inputs[i];
        DataType derivativeValue = function->computeDervative(computeH(x));
        deltas[i] = learningRate * outputError * function->computeDervative(computeH(x)) * x;

        inputWeights[i] += deltas[i];
    }
    return deltas;
}

void Neuron::checkInputNumber(DataVector const &inputs) const {
    if (inputs.size() != inputWeights.size()) {
        throw std::invalid_argument("input number mismatch");
    }
}

DataType inline Neuron::computeH(DataType x) {
    DataType h = 0;
    for (unsigned int i = 0; i < inputWeights.size(); ++i) {
        h += x * inputWeights[i];
    }
    return h;
}

