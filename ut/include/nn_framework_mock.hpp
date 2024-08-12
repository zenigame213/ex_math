#ifndef NN_FRAMEWORK_MOCK_H
#define NN_FRAMEWORK_MOCK_H

#include <gmock/gmock.h>
#include "Inn_framework.hpp"

namespace example
{

class NNFrameworkMock : public INN_Framework
{
public:
    MOCK_METHOD(bool, initNNFramework, (const std::string &config), (override));
    MOCK_METHOD(bool, detect, (const std::vector<float> &features), (override));
};

}

#endif
