#pragma once

#include <calculator/core/export.hpp>
#include <stdexcept>

namespace calculator {
namespace core {
namespace exceptions_base {

class CALCULATOR_CORE_EXPORT calculator_error_base
    :public std::runtime_error
{
public:
    calculator_error_base(const std::string &aMessage, const int &aErrorCode)
        :runtime_error(aMessage), m_ErrorCode(aErrorCode)
    {}

    int GetErrorCode() const
    {
        return m_ErrorCode;
    }

private:
    int m_ErrorCode;
};

}
}
}
