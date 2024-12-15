#pragma once
#include "Lexeme.hpp"
#include "Operator.hpp"

class Multiply : public Operator {
public:
    Multiply();

    double Evaluate(double* stack, int& stackSize) const override;
};