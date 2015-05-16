#include "ThreeLayerPerceptron.h"
ThreeLayerPerceptron::ThreeLayerPerceptron(const std::vector<unsigned> &neuronPerLayer,
                         std::vector<NeuronConfiguration> const &neuronConfigurationsForLayer, bool withBias,
                         bool showDebug) : withBias(withBias), showDebug(showDebug){
    for(unsigned long i = 0; i< neuronPerLayer.size(); ++i){
        bool allowBias = (i == 1 || i == 2) && withBias;
        bool withBiasNeuron = (i == 0 || i == 1) && withBias;
        layersVector.push_back(Layer(neuronConfigurationsForLayer.at(i), neuronPerLayer.at(i), allowBias,
                                     withBiasNeuron));
    }

    inputLayer = layersVector.at(0);
    hiddenLayer = layersVector.at(1);
    outputLayer = layersVector.at(2);
}

DataVector ThreeLayerPerceptron::output(DataVector const & input) {
    DataVectors inputVectors = prepareInputForInputLayer(input);
    DataVector inputLayerOutput = inputLayer.output(inputVectors);
    displayLayerOutput(0, inputLayerOutput);

    DataVector hiddenLayerOutput = hiddenLayer.output(inputLayerOutput);
    displayLayerOutput(1, hiddenLayerOutput);

    DataVector outputLayerOutput = outputLayer.output(hiddenLayerOutput);
    displayLayerOutput(2, outputLayerOutput);

    return outputLayerOutput;

}

DataVectors ThreeLayerPerceptron::prepareInputForInputLayer(DataVector const &input) {
    DataVectors inputVectors;
    for(DataVector::const_iterator it = input.cbegin(); it != input.cend(); ++it){
        DataVector tmp;
        tmp.push_back(*it);
        inputVectors.push_back(tmp);
    }
    if(withBias){
        inputVectors.push_back(DataVector {0});
    }
    return inputVectors;
}

void ThreeLayerPerceptron::train(DataVector const &inputs, DataVector const &desiredOutput) {
    DataVector outputs = output(inputs);
    DataVector errors;
    for(unsigned long i = 0; i< outputs.size(); ++i){
        errors.push_back((desiredOutput.at(i) - outputs.at(i)));
    }

    DataVector outputLayerErrorsToPropagate = outputLayer.prepareErrorForPropagation(errors, hiddenLayer.neuronsCount());

    DataVector inputLayerOutput = inputLayer.output(prepareInputForInputLayer(inputs));

    DataVector hiddenLayerOutput = hiddenLayer.output(inputLayerOutput);

    hiddenLayer.updateNeuronsWeights(inputLayerOutput, outputLayerErrorsToPropagate);
    outputLayer.updateNeuronsWeights(hiddenLayerOutput, errors);
}

void ThreeLayerPerceptron::displayLayerOutput(unsigned long layerNumber, const DataVector &vec) {
    if(showDebug){
        std::cout << layerNumber;
        for(DataVector::const_iterator it = vec.cbegin(); it != vec.cend(); ++it){
            std::cout << " " << *it;
        }
        std::cout << std::endl;
    }
}
