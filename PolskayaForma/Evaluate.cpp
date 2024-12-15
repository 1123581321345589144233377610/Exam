#include "Evaluate.hpp"

double Evaluate(Lexeme** lexemes, int lexemesCount) {
    double stack[MAX_STACK_SIZE];
    int stackSize = 0;

    for (int i = 0; i < lexemesCount; ++i) {
        if (!lexemes[i]) {
            throw std::runtime_error("Null lexeme encountered");
        }
        if (auto val = lexemes[i]->AsValue()) {
            stack[stackSize++] = *val;
        }
        else if (auto op = lexemes[i]->AsOperator()) {
            op->Evaluate(stack, stackSize);
        }
        else {
            throw std::runtime_error("Invalid lexeme");
        }
    }
    if (stackSize != 1) {
        throw std::runtime_error("Invalid expression");
    }
    return stack[0];
}