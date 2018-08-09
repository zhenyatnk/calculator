#include <calculator/core/IOperand.hpp>

#include <string>
#include <memory>

namespace calculator {
namespace core {
//////////////////////////////////////////////////////////////////////////////////////////
class CPlusOperation
:public IOperand
{
public:
    CPlusOperation(const std::shared_ptr<IOperand> &left, const std::shared_ptr<IOperand> &right)
    :m_left(left), m_right(right)
    {}
    
    virtual float GetResult() override
    {
        return m_left->GetResult() + m_right->GetResult();
    }
    
private:
    std::shared_ptr<IOperand> m_left;
    std::shared_ptr<IOperand> m_right;
};
//////////////////////////////////////////////////////////////////////////////////////////
class CMinusOperation
:public IOperand
{
public:
    CMinusOperation(const std::shared_ptr<IOperand> &left, const std::shared_ptr<IOperand> &right)
    :m_left(left), m_right(right)
    {}
    
    virtual float GetResult() override
    {
        return m_left->GetResult() - m_right->GetResult();
    }
    
private:
    std::shared_ptr<IOperand> m_left;
    std::shared_ptr<IOperand> m_right;
};
//////////////////////////////////////////////////////////////////////////////////////////
class CTimesOperation
:public IOperand
{
public:
    CTimesOperation(const std::shared_ptr<IOperand> &left, const std::shared_ptr<IOperand> &right)
    :m_left(left), m_right(right)
    {}
    
    virtual float GetResult() override
    {
        return m_left->GetResult() * m_right->GetResult();
    }
    
private:
    std::shared_ptr<IOperand> m_left;
    std::shared_ptr<IOperand> m_right;
};
//////////////////////////////////////////////////////////////////////////////////////////
class CDividedOperation
:public IOperand
{
public:
    CDividedOperation(const std::shared_ptr<IOperand> &left, const std::shared_ptr<IOperand> &right)
    :m_left(left), m_right(right)
    {}
    
    virtual float GetResult() override
    {
        if(!m_right->GetResult())
            throw exceptions::operation_error("Error divided operation - zero denominator");
        return m_left->GetResult() / m_right->GetResult();
    }
    
private:
    std::shared_ptr<IOperand> m_left;
    std::shared_ptr<IOperand> m_right;
};
//////////////////////////////////////////////////////////////////////////////////////////
std::unique_ptr<IOperand> CreateDoubleOperation(EArithmetic operation, const std::shared_ptr<IOperand> &left, const std::shared_ptr<IOperand> &right)
{
    switch (operation) {
        case EArithmetic::ePlus:
            return std::make_unique<CPlusOperation>(left, right);
        case EArithmetic::eMinus:
            return std::make_unique<CMinusOperation>(left, right);
        case EArithmetic::eTimes:
            return std::make_unique<CTimesOperation>(left, right);
        case EArithmetic::eDivided:
            return std::make_unique<CDividedOperation>(left, right);
    };
    throw exceptions::operation_error("Not operation for value '" + std::to_string(static_cast<int>(operation)));
}
    
}
}
