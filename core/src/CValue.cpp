#include <calculator/core/IOperand.hpp>

#include <memory>

namespace calculator {
namespace core {

class CValue
:public IOperand
{
public:
    explicit CValue(float value)
    :m_value(value)
    {}
    
    
    float GetResult() override
    {
        return m_value;
    }
    
private:
    float m_value;
};

std::unique_ptr<IOperand> CreateValue(float value)
{
    return std::make_unique<CValue>(value);
}
    
}
}
