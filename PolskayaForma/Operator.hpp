#pragma once
#include "Lexeme.hpp"

class Operator : public Lexeme {
public:
    Operator(const char* name);

    virtual double Evaluate(double* stack, int& stackSize) const = 0;

    const Operator* AsOperator() const override;

    Operator* AsOperator() override;
};