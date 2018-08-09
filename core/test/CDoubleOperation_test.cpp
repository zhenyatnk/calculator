#include <calculator/core/IOperand.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

//--------------------------------------------------
using namespace calculator::core;
using namespace testing;

class MockIOperand
    :public IOperand
{
public:
    MOCK_METHOD0(GetResult, float());
};

//--------------------------------------------------
class CDoubleOperation_test
    :public ::testing::Test
{
public:
    void SetUp()
    {
        m_left = std::make_shared<NiceMock<MockIOperand>>();
        m_right = std::make_shared<NiceMock<MockIOperand>>();
    }
    
protected:
    std::shared_ptr<MockIOperand> m_left;
    std::shared_ptr<MockIOperand> m_right;
};

TEST_F(CDoubleOperation_test, ePlus)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(1.1));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(4.4));
    
    ASSERT_FLOAT_EQ(5.5, CreateDoubleOperation(EArithmetic::ePlus, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eMinus1)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(1.1));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(4.4));
    
    ASSERT_FLOAT_EQ(-3.3, CreateDoubleOperation(EArithmetic::eMinus, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eMinus2)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(4.4));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(1.1));
    
    ASSERT_FLOAT_EQ(3.3, CreateDoubleOperation(EArithmetic::eMinus, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eTimes1)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(4));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(1.1));
    
    ASSERT_FLOAT_EQ(4.4, CreateDoubleOperation(EArithmetic::eTimes, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eTimes2)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(4.4));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(1.1));
    
    ASSERT_FLOAT_EQ(4.84, CreateDoubleOperation(EArithmetic::eTimes, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eTimes_zero)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(0));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(1.1));
    
    ASSERT_FLOAT_EQ(0, CreateDoubleOperation(EArithmetic::eTimes, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eTimes_dzero)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(0));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(0));
    
    ASSERT_FLOAT_EQ(0, CreateDoubleOperation(EArithmetic::eTimes, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eDivided1)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(1));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(2));
    
    ASSERT_FLOAT_EQ(0.5, CreateDoubleOperation(EArithmetic::eDivided, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eDivided2)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(4));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(2));
    
    ASSERT_FLOAT_EQ(2, CreateDoubleOperation(EArithmetic::eDivided, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eDivided3)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(4.84));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(1.1));
    
    ASSERT_FLOAT_EQ(4.4, CreateDoubleOperation(EArithmetic::eDivided, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eDivided_zero1)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(0));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(1.1));
    
    ASSERT_FLOAT_EQ(0, CreateDoubleOperation(EArithmetic::eDivided, m_left, m_right)->GetResult());
}

TEST_F(CDoubleOperation_test, eDivided_zero2)
{
    EXPECT_CALL(*m_left, GetResult()).WillRepeatedly(Return(1));
    EXPECT_CALL(*m_right, GetResult()).WillRepeatedly(Return(0));
    
    ASSERT_ANY_THROW(CreateDoubleOperation(EArithmetic::eDivided, m_left, m_right)->GetResult());
}
