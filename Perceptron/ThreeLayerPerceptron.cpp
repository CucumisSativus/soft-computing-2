#include "ThreeLayerPerceptron.h"
#include <iostream>
ThreeLayerPerceptron::ThreeLayerPerceptron(const std::vector<unsigned> &neuronPerLayer,
                                           std::vector<NeuronConfiguration> const &neuronConfigurationsForLayer){
    for(unsigned long i = 0; i< neuronPerLayer.size(); ++i){
        layersVector.push_back(Layer(neuronConfigurationsForLayer.at(i), neuronPerLayer.at(i)));
    }

    std::cout << "Layer 0 " <<layersVector.at(0).neuronsCount() << std::endl;
    std::cout << "Layer 1 " <<layersVector.at(1).neuronsCount() << std::endl;
    std::cout << "Layer 2 " <<layersVector.at(2).neuronsCount() << std::endl;

}

DataVector ThreeLayerPerceptron::output(DataVector const & input) {
    DataVectors inputVectors = prepareInput(input);
    DataVector inputLayerOutput = layersVector.at(0).output(inputVectors);

    DataVectors hiddenLayerInputs(layersVector.at(1).neuronsCount(), inputLayerOutput);
    DataVector hiddenLayerOutput = layersVector.at(1).output(hiddenLayerInputs);

    DataVectors outputLayerInputs(layersVector.at(2).neuronsCount(), hiddenLayerOutput);
    return layersVector.at(2).output(outputLayerInputs);

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
