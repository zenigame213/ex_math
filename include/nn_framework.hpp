#ifndef EXAMPLE_NN_FRAMEWORK_HPP
#define EXAMPLE_NN_FRAMEWORK_HPP

#include <string>
#include <vector>
#include <memory>
#include "Inn_framework.hpp"
#include "ex_nn.hpp"

namespace example
{

class NNFramework : public INN_Framework
{
public:
    NNFramework();
    bool initNNFramework(const std::string &config) override;
    bool detect(const std::vector<float> &features) override;

private:
    std::shared_ptr<NN> nn;
    bool initialized{false};
};
}

#endif
