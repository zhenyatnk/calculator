#pragma once

#include <calculator/core/export.hpp>
#include <stdexcept>

namespace calculator {
namespace core {
namespace exceptions_base {

class CALCULATOR_CORE_EXPORT error_base
    :public std::runtime_error
{
public:
    error_base(const std::string &aMessage)
        :runtime_error(aMessage)
    {}
};

}
}
}
