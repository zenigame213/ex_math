#ifndef EXAMPLE_LIB_NN_HPP
#define EXAMPLE_LIB_NN_HPP

#include <string>
#include <vector>

namespace example
{

class NN
{
public:
    NN();
    bool initializeNN(const std::string &config);
    bool detect(const std::vector<float> &features);

private:
    bool initialized{false};
};
}

#endif
