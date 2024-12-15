#pragma once
#include "Lexeme.hpp"
#include "Operator.hpp"

class Subtract : public Operator {
public:
    Subtract();

    double Evaluate(double* stack, int& stackSize) const override;
};