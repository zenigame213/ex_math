#include <iostream>
#include <cassert>
#include "ex_math.hpp"
#include "ex_calculator.hpp"
#include "nn_framework.hpp"

namespace example
{

Math::Math()
{
#ifndef WITH_UT
    nnFramework = std::make_shared<NNFramework>();
    calculator = std::make_shared<Calculator>();
#endif
}

bool Math::init(const std::string &config)
{
    if (config == "")
    {
        std::cerr << "libex_math initialize failed!! config path is empty." << std::endl;
        return false;
    }
    else if (initialized)
    {
        std::cerr << "libex_math is already initialized." << std::endl;
        return false;
    }

    // load Neural Network model
    if (!nnFramework->initNNFramework(config))
    {
        std::cerr << "NN framework initialize failed!!" << std::endl;
        return false;
    }
    std::cout << "libex_math initialized successfully." << std::endl;
    initialized = true;
    return true;
}

int Math::add(const int v1, const int v2)
{
    return calculator->add(v1, v2);
}

bool Math::detect(const std::vector<float> &features)
{
    assert(initialized);
    return nnFramework->detect(features);
}

#ifdef WITH_UT
void Math::setNNFrameworkMock(std::shared_ptr<INN_Framework> nnFrameworkMock)
{
    nnFramework = nnFrameworkMock;
}
#endif
}
