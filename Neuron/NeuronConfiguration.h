//
// Created by Michał Gutowski on 21.04.15.
//

#ifndef LAYERPERCEPTRON_NEURONCONFIGURATION_H
#define LAYERPERCEPTRON_NEURONCONFIGURATION_H

#include "../ActivationFunctions/ActivationFunction.h"
#include "../Defines.h"

class NeuronConfiguration {
public:
    NeuronConfiguration(int inputNumber, ActivationFunction *function, DataType neuronInitialWeights,
                        DataType learningRate);
    NeuronConfiguration(const NeuronConfiguration & original);
    int getInputNumber() const;
    void setInputNumber(int inputNumber);
    ActivationFunction *getFunction() const;
    void setFunction(ActivationFunction *function);
    DataType getNeuronInitialWeights() const;
    void setNeuronInitialWeights(DataType neuronInitialWeights);
    DataType getLearningRate() const;
    void setLearningRate(DataType learningRate);
private:
    int inputNumber;
    ActivationFunction *function;
    DataType neuronInitialWeights;
    DataType learningRate;
};


#endif //3LAYERPERCEPTRON_NEURONCONFIGURATION_H
