#pragma once

#include "Utils/ClassUtils.h"
#include "TechsetFileParserState.h"
#include "Techset/TechsetDefinition.h"
#include "Parsing/Simple/SimpleLexer.h"
#include "Parsing/Simple/SimpleParserValue.h"
#include "Parsing/Impl/AbstractParser.h"

namespace techset
{
    class Parser final : public AbstractParser<SimpleParserValue, ParserState>
    {
    protected:
        const std::vector<sequence_t*>& GetTestsForState() override;

    public:
        Parser(SimpleLexer* lexer, const char** validTechniqueTypeNames, size_t validTechniqueTypeNameCount);
        _NODISCARD std::unique_ptr<TechsetDefinition> GetTechsetDefinition() const;
    };
}
