//
// Created by Michał Gutowski on 21.04.15.
//

#ifndef LAYERPERCEPTRON_NEURONCONFIGURATION_H
#define LAYERPERCEPTRON_NEURONCONFIGURATION_H

#include <random>
#include <time.h>
#include "../ActivationFunctions/ActivationFunction.h"
#include "../Defines.h"

class NeuronConfiguration {
public:
    NeuronConfiguration(int inputNumber, ActivationFunction *function, DataType neuronInitialWeights,
                        DataType learningRate);
    NeuronConfiguration(int inputNumber, ActivationFunction *function, DataType learningRate);
    NeuronConfiguration(const NeuronConfiguration & original);
    int getInputNumber() const;
    void setInputNumber(int inputNumber);
    ActivationFunction *getFunction() const;
    void setFunction(ActivationFunction *function);
    DataType getNeuronInitialWeights() const;
    void setNeuronInitialWeights(DataType neuronInitialWeights);
    DataType getLearningRate() const;
    void setLearningRate(DataType learningRate);
    void allowBias();
private:
    int inputNumber;
    ActivationFunction *function;
    DataType neuronInitialWeights;
    DataType learningRate;
    bool randomWeights;
    std::uniform_real_distribution<double> distribution;
    std::default_random_engine engine;
};


#endif //3LAYERPERCEPTRON_NEURONCONFIGURATION_H
