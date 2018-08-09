#pragma once

#include <calculator/core/export.hpp>
#include <calculator/core/BaseExceptions.hpp>

#include <string>

namespace calculator {
namespace core {
namespace exceptions {

class CALCULATOR_CORE_EXPORT converter_error
    :public exceptions_base::error_base
{
public:
    converter_error(const std::string &aMessage)
    :exceptions_base::error_base("Converter error: \'" + aMessage + "\'")
    {}
};

}
}
}
