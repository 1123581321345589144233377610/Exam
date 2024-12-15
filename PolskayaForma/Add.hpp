#pragma once
#include "Lexeme.hpp"
#include "Operator.hpp"

class Add : public Operator {
public:
    Add();

    double Evaluate(double* stack, int& stackSize) const override;
};