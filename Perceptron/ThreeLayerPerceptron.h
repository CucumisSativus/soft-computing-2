//
// Created by Michał Gutowski on 21.04.15.
//

#ifndef LAYERPERCEPTRON_THREELAYERPERCEPTRON_H
#define LAYERPERCEPTRON_THREELAYERPERCEPTRON_H

#include <vector>
#include "../Defines.h"
#include "Layer.h"

class ThreeLayerPerceptron {
public:
    ThreeLayerPerceptron(const std::vector<unsigned> &neuronPerLayer,
                         std::vector<NeuronConfiguration> const &neuronConfigurationsForLayer);
    DataVector output(const DataVector & input);
private:
    std::vector<Layer> layersVector;

    DataVectors prepareInput(DataVector const &input);
};


#endif //3LAYERPERCEPTRON_THREELAYERPERCEPTRON_H
