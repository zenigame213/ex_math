#ifndef EXAMPLE_LIB_MATH_HPP
#define EXAMPLE_LIB_MATH_HPP

#include <string>
#include <vector>
#include <memory>
#include "Inn_framework.hpp"
#include "Icalculator.hpp"

namespace example
{

class Math
{
public:
    Math();
    bool init(const std::string &config);
    int add(const int v1, const int v2);
    bool detect(const std::vector<float> &features);
#ifdef WITH_UT
    void setNNFrameworkMock(std::shared_ptr<INN_Framework> nnFrameworkMock);
#endif

private:
    bool initialized{false};
    std::shared_ptr<INN_Framework> nnFramework;
    std::shared_ptr<ICalculator> calculator;
};
}

#endif
