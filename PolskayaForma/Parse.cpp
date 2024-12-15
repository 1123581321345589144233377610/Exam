#include "Parse.hpp"

void Parse(FILE* fin, Lexeme** lexemes, int& lexemesCount) {
    lexemesCount = 0;
    char token[256];

    std::unordered_map <std::string, Operator*> operatorFactories = {
        {Add().GetName(), new Add()},
        {Subtract().GetName(), new Subtract()},
        {Multiply().GetName(), new Multiply()},
        {Divide().GetName(), new Divide()},
        {Sin().GetName(), new Sin()},
        {Cos().GetName(), new Cos()}
    };
    while (fscanf(fin, "%s", token) == 1) {
        if (lexemesCount >= MAX_LEXEMES_NUM) {
            throw std::runtime_error("Exceeded maximum lexemes count");
        } 
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            lexemes[lexemesCount++] = new Value(std::stod(token), token);
        }else {
            auto it = operatorFactories[token];
            lexemes[lexemesCount++] = it;
        }
    }
}