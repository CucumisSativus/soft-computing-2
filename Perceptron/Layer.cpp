//
// Created by Michał Gutowski on 21.04.15.
//

#include "Layer.h"


Layer::Layer(const NeuronConfiguration &neuronConfiguration, int neuronsInLayer)
            : neuronsVector(neuronsInLayer, Neuron(neuronConfiguration)){

}

DataVector Layer::output(const DataVectors &inputs) {
    if(inputs.size() != neuronsVector.size()){
        throw std::invalid_argument("number od data vectors must match neurons in layer number");
    }
    DataVector output;
    for(unsigned long i =0; i< inputs.size(); ++i){
        DataType neuronOutput = neuronsVector.at(i).output(inputs.at(i));
        output.push_back(neuronOutput);
    }
    return output;
}

Neuron Layer::neuronAt(unsigned long index) {
    return neuronsVector.at(index);
}

unsigned long Layer::neuronsCount() {
    return neuronsVector.size();
}
