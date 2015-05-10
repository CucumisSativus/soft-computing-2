//
// Created by Michał Gutowski on 21.04.15.
//

#include "Layer.h"


Layer::Layer(const NeuronConfiguration &neuronConfiguration, int neuronsInLayer) {
    for(int i =0; i< neuronsInLayer; ++i){
        neuronsVector.push_back(Neuron(neuronConfiguration));
    }

}

DataVector Layer::output(const DataVectors &prepared_inputs) {
    if(prepared_inputs.size() != neuronsVector.size()){
        throw std::invalid_argument("number od data vectors must match neurons in layer number");
    }
    DataVector output;
    for(unsigned long i =0; i< prepared_inputs.size(); ++i){
        DataType neuronOutput = neuronsVector.at(i).output(prepared_inputs.at(i));
        output.push_back(neuronOutput);
    }
    return output;
}

DataVector Layer::output(const DataVector &raw_inputs) {
    DataVectors prepared_inputs(neuronsCount(), raw_inputs);
    return output(prepared_inputs);
}

Neuron Layer::neuronAt(unsigned long index) {
    return neuronsVector.at(index);
}

unsigned long Layer::neuronsCount() {
    return neuronsVector.size();
}

DataVector Layer::prepareErrorForPropagation(DataVector const &errors, unsigned long nextLayerNeuronsNumber) {
    DataVector errorsToPropagate(nextLayerNeuronsNumber, 0);
    for(unsigned long neuronInNextLayerIndex =0; neuronInNextLayerIndex < nextLayerNeuronsNumber; ++neuronInNextLayerIndex){
        for(unsigned long errorIndex =0; errorIndex < errors.size(); ++errorIndex) {
            DataType neuronWeight = neuronsVector.at(
                                neuronInNextLayerIndex).weightAt(
                                neuronInNextLayerIndex);
            errorsToPropagate.at(neuronInNextLayerIndex) += errors.at(errorIndex) * neuronWeight;
        }
    }
    return errorsToPropagate;
}

Layer::Layer() {

}

void Layer::updateNeuronsWeights(DataVectors const &inputs, DataVector const &errors) {
    if(errors.size() != neuronsVector.size() || inputs.size() != neuronsVector.size()){
        throw std::invalid_argument("number od data vectors must match neurons in layer number");
    }

    for(unsigned long i =0; i< neuronsVector.size(); ++i){
        neuronsVector.at(i).updateWights(inputs.at(i), errors.at(i));
    }

}

void Layer::updateNeuronsWeights(DataVector const &raw_inputs, DataVector const &errors) {
    DataVectors prepared_inputs(neuronsCount(), raw_inputs);
    updateNeuronsWeights(prepared_inputs, errors);
}
