#include <calculator/core/Converter.hpp>

#include <gtest/gtest.h>

//--------------------------------------------------
using namespace calculator::core;

class Converter_test
    :public ::testing::Test
{
public:
    void SetUp()
    {}
};

TEST_F(Converter_test, to_float_int)
{
    ASSERT_FLOAT_EQ(1, ConvertTo<float>("1"));
}

TEST_F(Converter_test, to_float_float1)
{
    ASSERT_FLOAT_EQ(1.1, ConvertTo<float>("1.1"));
}

TEST_F(Converter_test, to_float_float2)
{
    ASSERT_FLOAT_EQ(1.2, ConvertTo<float>("1,2"));
}

TEST_F(Converter_test, to_float_float3)
{
    ASSERT_FLOAT_EQ(0.2, ConvertTo<float>(",2"));
}

TEST_F(Converter_test, to_float_float4)
{
    ASSERT_FLOAT_EQ(1.0, ConvertTo<float>("1,"));
}

TEST_F(Converter_test, to_float_delim1)
{
    ASSERT_ANY_THROW(ConvertTo<float>(","));
}

TEST_F(Converter_test, to_float_delim2)
{
    ASSERT_ANY_THROW(ConvertTo<float>("."));
}

TEST_F(Converter_test, to_float_empty)
{
    ASSERT_FLOAT_EQ(0, ConvertTo<float>(""));
}

TEST_F(Converter_test, to_float_not_digit)
{
    ASSERT_ANY_THROW(ConvertTo<float>("asd"));
}

TEST_F(Converter_test, to_EArithmetic_ePlus)
{
    ASSERT_EQ(EArithmetic::ePlus, ConvertTo<EArithmetic>("+"));
}

TEST_F(Converter_test, to_EArithmetic_eMinus)
{
    ASSERT_EQ(EArithmetic::eMinus, ConvertTo<EArithmetic>("-"));
}

TEST_F(Converter_test, to_EArithmetic_eTimes)
{
    ASSERT_EQ(EArithmetic::eTimes, ConvertTo<EArithmetic>("*"));
}

TEST_F(Converter_test, to_EArithmetic_eDivided)
{
    ASSERT_EQ(EArithmetic::eDivided, ConvertTo<EArithmetic>("/"));
}

TEST_F(Converter_test, to_EArithmetic_empty)
{
   ASSERT_ANY_THROW(ConvertTo<EArithmetic>(""));
}

TEST_F(Converter_test, to_EArithmetic_wrong)
{
    ASSERT_ANY_THROW(ConvertTo<EArithmetic>("1"));
}

TEST_F(Converter_test, SafeConvertTo_EArithmetic)
{
    EArithmetic value;
    ASSERT_EQ(true, SafeConvertTo<EArithmetic>("+", value));
}

TEST_F(Converter_test, SafeConvertTo_EArithmetic_wrong)
{
    EArithmetic value;
    ASSERT_EQ(false, SafeConvertTo<EArithmetic>("1", value));
}

