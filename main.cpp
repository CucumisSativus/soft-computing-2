#include <iostream>
#include <iomanip>
#include "Perceptron/ThreeLayerPerceptron.h"
#include "ActivationFunctions/LinearFunction.h"
#include "ActivationFunctions/SineFunction.h"
#include "ActivationFunctions/SigmoidalFunction.h"
void printDataVector(DataVector const &output){
    std::cout << "[";
    std::cout.precision(4);
    for(DataVector::const_iterator it = output.cbegin(); it != output.cend(); ++it){
        std::cout <<  std::fixed << *it << " ";
    }
    std::cout << "]" << std::endl;
}
void printOutputForSet(ThreeLayerPerceptron & perceptron, DataVector const & inputSet, DataVector const & outputSet){
    std::cout << "input\t\t\t\t";
    printDataVector(inputSet);
    std::cout << "neuron output\t\t";
    printDataVector(perceptron.output(inputSet));
    std::cout << "expected output\t\t";
    printDataVector(outputSet);

    std::cout<< "==================================================" << std::endl;
}
int main() {
    std::vector<unsigned> neuronsPerLayer {4,2,4};
    NeuronConfiguration inputLayerConfiguration(1, new LinearFunction(), 0.3);
    NeuronConfiguration hiddenLayerConfiguration(4, new SigmoidalFunction(), 0.3);
    NeuronConfiguration outputLayerConfiguration(2, new SigmoidalFunction(), 0.3);

    std::vector<NeuronConfiguration> neuronConfigurationsPerLayer;
    neuronConfigurationsPerLayer.push_back(inputLayerConfiguration);
    neuronConfigurationsPerLayer.push_back(hiddenLayerConfiguration);
    neuronConfigurationsPerLayer.push_back(outputLayerConfiguration);


    ThreeLayerPerceptron perceptron(neuronsPerLayer, neuronConfigurationsPerLayer, true, false);

    DataVectors testInputs {
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}
    };
    DataVectors testOutputs {
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}
    };

    const unsigned int TRAINING_EPOCH_NUMBER = 100000;

    if(testInputs.size() != testOutputs.size()){
        std::cerr << "test inputs and outputs size mismatch" << std::endl;
        return 1;
    }

    for (unsigned int epoch =0; epoch < TRAINING_EPOCH_NUMBER; ++epoch) {
        for(unsigned long set=0; set < testInputs.size(); ++set){
            perceptron.train(testInputs.at(set), testOutputs.at(set));
            if(epoch % (TRAINING_EPOCH_NUMBER/100) == 0){
                printOutputForSet(perceptron, testInputs.at(set), testOutputs.at(set));
            }
        }
    }

    for(unsigned long set=0; set < testInputs.size(); ++set){
        std::cout << std::endl << std::endl;
        std::cout << "\tFinal results\t" << std::endl << "==================================================" << std::endl;
        printOutputForSet(perceptron, testInputs.at(set), testOutputs.at(set));

    }
    return 0;
}