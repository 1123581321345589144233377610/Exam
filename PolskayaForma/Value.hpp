#pragma once
#include "Lexeme.hpp"

class Value : public Lexeme {
private:
    double value;

public:
    Value(double value, const char* name);

    operator double() const;

    const Value* AsValue() const override;

    Value* AsValue() override;
};