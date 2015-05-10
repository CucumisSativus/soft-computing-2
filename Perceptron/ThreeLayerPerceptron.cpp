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
}

DataVector ThreeLayerPerceptron::output(DataVector const & input) {
    DataVectors inputVectors = prepareInputForInputLayer(input);
    DataVector inputLayerOutput = inputLayer.output(inputVectors);


    DataVector hiddenLayerOutput = hiddenLayer.output(inputLayerOutput);

    return outputLayer.output(hiddenLayerOutput);

}

DataVectors ThreeLayerPerceptron::prepareInputForInputLayer(DataVector const &input) {
    DataVectors inputVectors;
    for(DataVector::const_iterator it = input.cbegin(); it != input.cend(); ++it){
        DataVector tmp;
        tmp.push_back(*it);
        inputVectors.push_back(tmp);
    }
    return inputVectors;
}

void ThreeLayerPerceptron::train(DataVector const &inputs, DataVector const &desiredOutput) {
    DataVector outputs = output(inputs);
    DataVector errors;
    for(unsigned long i = 0; i< outputs.size(); ++i){
        errors.push_back((desiredOutput.at(i) - outputs.at(i)) * (outputs.at(i) * (1 - outputs.at(i))));
    }

    DataVector outputLayerErrorsToPropagate = outputLayer.prepareErrorForPropagation(errors, hiddenLayer.neuronsCount());

    DataVector inputLayerOutput = inputLayer.output(prepareInputForInputLayer(inputs));

    DataVector hiddenLayerOutput = hiddenLayer.output(inputLayerOutput);

    hiddenLayer.updateNeuronsWeights(inputLayerOutput, outputLayerErrorsToPropagate);
    outputLayer.updateNeuronsWeights(hiddenLayerOutput, errors);
}

