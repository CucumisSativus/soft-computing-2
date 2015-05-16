//
// Created by Michał Gutowski on 21.04.15.
//

#include "NeuronConfiguration.h"
#include <random>

NeuronConfiguration::NeuronConfiguration(int inputNumber, ActivationFunction *function, DataType neuronInitialWeights,
                                         DataType learningRate) : inputNumber(inputNumber), function(function),
                                                                  neuronInitialWeights(neuronInitialWeights),
                                                                  learningRate(learningRate), randomWeights(false) {

}

NeuronConfiguration::NeuronConfiguration(const NeuronConfiguration &original) {
    inputNumber = original.getInputNumber();
    neuronInitialWeights = original.getNeuronInitialWeights();
    learningRate = original.getLearningRate();
    function = original.function->clone();
}

int NeuronConfiguration::getInputNumber() const {
    return inputNumber;
}

void NeuronConfiguration::setInputNumber(int inputNumber) {
    NeuronConfiguration::inputNumber = inputNumber;
}

ActivationFunction *NeuronConfiguration::getFunction() const {
    return function;
}

void NeuronConfiguration::setFunction(ActivationFunction *function) {
    NeuronConfiguration::function = function;
}

DataType NeuronConfiguration::getNeuronInitialWeights() const {
    if(randomWeights){
        std::uniform_real_distribution<double> distribution(-0.5, 0.5);
        std::default_random_engine engine;
        double rate = distribution(engine);
        return rate;
    }
    return neuronInitialWeights;
}

void NeuronConfiguration::setNeuronInitialWeights(DataType neuronInitialWeights) {
    NeuronConfiguration::neuronInitialWeights = neuronInitialWeights;
}

DataType NeuronConfiguration::getLearningRate() const {
        return learningRate;
}

void NeuronConfiguration::setLearningRate(DataType learningRate) {
    NeuronConfiguration::learningRate = learningRate;
}

NeuronConfiguration::NeuronConfiguration(int inputNumber, ActivationFunction *function, DataType learningRate)
        : inputNumber(inputNumber), function(function), learningRate(learningRate), randomWeights(true) {

}

void NeuronConfiguration::allowBias() {
    inputNumber++;
}
