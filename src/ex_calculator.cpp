#include "ex_calculator.hpp"

namespace example
{
Calculator::Calculator()
{}

int Calculator::add(const int v1, const int v2)
{
    int out = v1 + v2;
    if (out > 255)
    {
        out = 255;
    }
    return out;
}

}
