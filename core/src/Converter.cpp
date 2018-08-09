#include <calculator/core/Converter.hpp>

#include <string>
#include <sstream>
#include <memory>

namespace calculator {
namespace core {
namespace
{
bool IsDigit(const std::string& str)
{
    for(const auto & ch: str)
        if(!std::isdigit(ch) && ch !=',' && ch != '.')
            return false;
    return str != "" && str != "." && str != ",";
}
    
void findAndReplace(std::string& str, const std::string& oldStr, const std::string& newStr)
{
    std::string::size_type pos = 0u;
    while((pos = str.find(oldStr, pos)) != std::string::npos){
        str.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
}
    
}
    
template<>
float ConvertTo(const std::string& str)
{
    if("" == str)
        return 0;
    if(!IsDigit(str))
        throw exceptions::converter_error("Cannot convert '" + str + "' to float");
    
    auto stringFloat = str;
    findAndReplace(stringFloat, ",", ".");
    std::stringstream sstr(stringFloat);
    float value = 0;
    sstr >> value;
    return value;
}
    
template<>
EArithmetic ConvertTo(const std::string& str)
{
    if("+" == str)
        return EArithmetic::ePlus;
    else if("-" == str)
        return EArithmetic::eMinus;
    else if("*" == str)
        return EArithmetic::eTimes;
    else if("/" == str)
        return EArithmetic::eDivided;
    else
        throw exceptions::converter_error("Cannot convert '" + str + "' to EArithmetic");
}
    
}
}
