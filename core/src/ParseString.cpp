#include <calculator/core/BaseExceptions.hpp>
#include <string>
#include <sstream>
#include <memory>

namespace calculator {
namespace core {
/*
std::string RemoveBrackets(const std::string & str)
{
    
}

offset GetOffsetOperation(const std::string & str)
{
    std::vector<std::pair<offset, enum_operation>> operations;
    
    int level_brackets = 0;
    int offset = 0;
    for(const auto &s : str)
    {
        if(IsAripmetics(s) && !level_brackets)
            operations.push_back({offset, ToAripmetics(s)});
        ++offset;
    }
    
}

std::unique_ptr<IOperand> ParseString(const std::string & str)
{
    auto str_ = RemoveBrackets(str);
    auto offset_operation = GetOffsetOperation(str_);
    if(offset_operation == endpos)
        return CreateValue(str_);
    else
        return CreateAbstractDoubleOperation(enum_operation, ParseString(str), ParseString(str + offset_operation));
}*/
    
}
}
