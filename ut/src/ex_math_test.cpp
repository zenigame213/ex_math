#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>
#include "ex_math.hpp"
#include "nn_framework_mock.hpp"

namespace example
{
using ::testing::Return;

class UT_MathTest : public ::testing::Test
{
protected:
    std::string config;

    void SetUp() override
    {
        config = "neuralnetwork.mdl";
    };
};

/**
 @brief Test case for initialize Math instance
*/
TEST_F(UT_MathTest, initTest)
{
    Math math;

    auto nn_framework_mock = std::make_shared<NNFrameworkMock>();
    EXPECT_CALL(*nn_framework_mock, initNNFramework)
        .Times(1)
        .WillOnce(Return(true));

    math.setNNFrameworkMock(nn_framework_mock);

    EXPECT_EQ(true, math.init(config));
    EXPECT_EQ(false, math.init(config));
}
}