#pragma once
#include "Lexeme.hpp"
#include "Operator.hpp"

class Sin : public Operator {
public:
    Sin();

    double Evaluate(double* stack, int& stackSize) const override;
};