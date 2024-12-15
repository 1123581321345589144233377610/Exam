#pragma once
#include "Lexeme.hpp"
#include "Operator.hpp"

class Cos : public Operator {
public:
    Cos();

    double Evaluate(double* stack, int& stackSize) const override;
};