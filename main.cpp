#include <iostream>
#include "Perceptron/ThreeLayerPerceptron.h"
#include "ActivationFunctions/LinearFunction.h"
#include "ActivationFunctions/SineFunction.h"
#include "ActivationFunctions/SigmoidalFunction.h"
int main() {
    std::vector<unsigned> neuronsPerLayer {4,2,4};
    NeuronConfiguration inputLayerConfiguration(1, new LinearFunction(), 1, 0.01);
    NeuronConfiguration hiddenLayerConfiguration(4, new SigmoidalFunction(), 1, 0.01);
    NeuronConfiguration outputLayerConfiguration(2, new SigmoidalFunction(), 1, 0.01);

    std::vector<NeuronConfiguration> neuronConfigurationsPerLayer;
    neuronConfigurationsPerLayer.push_back(inputLayerConfiguration);
    neuronConfigurationsPerLayer.push_back(hiddenLayerConfiguration);
    neuronConfigurationsPerLayer.push_back(outputLayerConfiguration);


    ThreeLayerPerceptron perceptron(neuronsPerLayer, neuronConfigurationsPerLayer);

    DataVector input {1,1,1,1};

    DataVector output = perceptron.output(input);
    for(DataVector::iterator it = output.begin(); it != output.end(); ++it){
        std::cout << *it << std::endl;
    }

    return 0;
}