#pragma once

#include <calculator/core/IOperandExceptions.hpp>
#include <calculator/core/EArithmetic.hpp>
#include <memory>

namespace calculator {
namespace core {
    
class IOperand
{
public:
    virtual ~IOperand() = default;
    
    virtual float GetResult() = 0;
};

std::unique_ptr<IOperand> CreateDoubleOperation(EArithmetic operation, const std::shared_ptr<IOperand> &left, const std::shared_ptr<IOperand> &right);
std::unique_ptr<IOperand> CreateValue(float value);

}
}
