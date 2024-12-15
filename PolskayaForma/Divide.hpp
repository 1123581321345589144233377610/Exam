#pragma once
#include "Lexeme.hpp"
#include "Operator.hpp"

class Divide : public Operator {
public:
    Divide();

    double Evaluate(double* stack, int& stackSize) const override;
};