//
// Created by Michał Gutowski on 21.04.15.
//

#ifndef LAYERPERCEPTRON_LAYER_H
#define LAYERPERCEPTRON_LAYER_H

#include "../Defines.h"
#include "../Neuron/Neuron.h"

class Layer {
public:
    Layer(const NeuronConfiguration &neuronConfiguration, int neuronsInLayer);
    Layer();

    DataVector output(const DataVectors &prepared_inputs);
    DataVector output(const DataVector &raw_inputs);
    Neuron neuronAt(unsigned long index);
    unsigned long neuronsCount();
    DataVector prepareErrorForPropagation(DataVector const &errors, unsigned long nextLayerNeuronsNumber);
    void updateNeuronsWeights(DataVectors const &inputs, DataVector const &errors);
    void updateNeuronsWeights(DataVector const &raw_inputs, DataVector const &errors);
private:
    std::vector<Neuron> neuronsVector;
};


#endif //3LAYERPERCEPTRON_LAYER_H
