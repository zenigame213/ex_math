#ifndef ICALCULATOR_HPP
#define ICALCULATOR_HPP

namespace example
{

class ICalculator
{
public:
    virtual ~ICalculator() = default;
    virtual int add(const int v1, const int v2) = 0;
};

}

#endif
