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
    DataVector output(const DataVectors &inputs);
    Neuron neuronAt(unsigned long index);
    unsigned long neuronsCount();
private:
    std::vector<Neuron> neuronsVector;
};


#endif //3LAYERPERCEPTRON_LAYER_H
