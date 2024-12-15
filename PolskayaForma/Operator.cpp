#include "Operator.hpp"

Operator::Operator(const char* name) : Lexeme(name) {}

const Operator* Operator::AsOperator() const {
    return this;
}

Operator* Operator::AsOperator() {
    return this;
}