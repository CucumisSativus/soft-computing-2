cmake_minimum_required(VERSION 3.0)
project(3layerperceptron)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(3layerperceptron ${SOURCE_FILES} Neuron/Neuron.cpp Neuron/Neuron.h Defines.h ActivationFunctions/ActivationFunction.h ActivationFunctions/LinearFunction.cpp ActivationFunctions/LinearFunction.h Perceptron/ThreeLayerPerceptron.cpp Perceptron/ThreeLayerPerceptron.h Perceptron/Layer.cpp Perceptron/Layer.h Neuron/NeuronConfiguration.cpp Neuron/NeuronConfiguration.h ActivationFunctions/SineFunction.cpp ActivationFunctions/SineFunction.h ActivationFunctions/SigmoidalFunction.cpp ActivationFunctions/SigmoidalFunction.h)