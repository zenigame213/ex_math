#include <cassert>
#include "nn_framework.hpp"
#include "ex_nn.hpp"

namespace example
{

NNFramework::NNFramework()
{}

bool NNFramework::initNNFramework(const std::string &config)
{
    if (config == "")
    {
        return false;
    }

    nn = std::make_shared<NN>();
    if (!nn->initializeNN(config))
    {
        return false;
    }

    initialized = true;
    return true;
}

bool NNFramework::detect(const std::vector<float> &features)
{
    assert(initialized);
    return nn->detect(features);
}
}
