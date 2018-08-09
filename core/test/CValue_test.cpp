#include <calculator/core/IOperand.hpp>

#include <gtest/gtest.h>

//--------------------------------------------------
using namespace calculator::core;

class CValue_test
    :public ::testing::Test
{
public:
    void SetUp()
    {}
};

TEST_F(CValue_test, null)
{
    auto value = CreateValue(0);
    ASSERT_FLOAT_EQ(0, value->GetResult());
}

TEST_F(CValue_test, float)
{
    auto value = CreateValue(1.2);
    ASSERT_FLOAT_EQ(1.2, value->GetResult());
}
