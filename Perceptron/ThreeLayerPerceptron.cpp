#include "ThreeLayerPerceptron.h"
#include <iostream>
ThreeLayerPerceptron::ThreeLayerPerceptron(const std::vector<unsigned> &neuronPerLayer,
                                           std::vector<NeuronConfiguration> const &neuronConfigurationsForLayer){
    for(unsigned long i = 0; i< neuronPerLayer.size(); ++i){
        layersVector.push_back(Layer(neuronConfigurationsForLayer.at(i), neuronPerLayer.at(i)));
    }

    inputLayer = layersVector.at(0);
    hiddenLayer = layersVector.at(1);
    outputLayer = layersVector.at(2);

    std::cout << "Layer 0 " <<layersVector.at(0).neuronsCount() << std::endl;
    std::cout << "Layer 1 " <<layersVector.at(1).neuronsCount() << std::endl;
    std::cout << "Layer 2 " <<layersVector.at(2).neuronsCount() << std::endl;

}

DataVector ThreeLayerPerceptron::output(DataVector const & input) {
    DataVectors inputVectors = prepareInput(input);
    DataVector inputLayerOutput = inputLayer.output(inputVectors);


    DataVectors hiddenLayerInputs(hiddenLayer.neuronsCount(), inputLayerOutput);
    DataVector hiddenLayerOutput = hiddenLayer.output(hiddenLayerInputs);

    DataVectors outputLayerInputs(outputLayer.neuronsCount(), hiddenLayerOutput);
    return outputLayer.output(outputLayerInputs);

}

DataVectors ThreeLayerPerceptron::prepareInput(DataVector const &input) {
    DataVectors inputVectors;
    for(DataVector::const_iterator it = input.cbegin(); it != input.cend(); ++it){
        DataVector tmp;
        tmp.push_back(*it);
        inputVectors.push_back(tmp);
    }
    return inputVectors;
}

void ThreeLayerPerceptron::train(DataVector const &inputs, DataVector const &desiredOutputs) {
    DataVector outputs = output(inputs);
    DataVector errors;
    for(unsigned long i = 0; i< outputs.size(); ++i){
        errors.push_back(desiredOutputs[i] - outputs[i]);
    }

    DataVector outputLayerErrorsToPropagate = outputLayer.prepareErrorForPropagation(errors, hiddenLayer.neuronsCount());
    DataVector hiddenLayerErrorsToPropagate = hiddenLayer.prepareErrorForPropagation(outputLayerErrorsToPropagate, inputLayer.neuronsCount());

    
    
    
}

