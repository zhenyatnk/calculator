#pragma once

#include <calculator/core/ConverterExceptions.hpp>
#include <calculator/core/EArithmetic.hpp>
#include <string>

namespace calculator {
namespace core {
    
template<typename Type>
Type ConvertTo(const std::string& str)
{
    static_assert(sizeof(char), "not implementation convert");
}
    
template<typename Type>
bool SafeConvertTo(const std::string& str, Type& value)
{
    try
    {
        value = ConvertTo<Type>(str);
        return true;
    }
    catch(exceptions::converter_error&)
    {
        return false;
    }
}

template<> float ConvertTo(const std::string& str);
template<> EArithmetic ConvertTo(const std::string& str);

}
}
