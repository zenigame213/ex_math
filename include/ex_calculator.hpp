#ifndef EXAMPLE_CALCULATOR_HPP
#define EXAMPLE_CALCULATOR_HPP

#include "Icalculator.hpp"

namespace example
{

class Calculator : public ICalculator
{
public:
    Calculator();
    int add(const int v1, const int v2) override;
private:
    bool initialized;
};

}

#endif
