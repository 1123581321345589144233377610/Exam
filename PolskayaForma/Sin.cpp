#include "Sin.hpp"

Sin::Sin() : Operator("sin") {}

double Sin::Evaluate(double* stack, int& stackSize) const {
    if (stackSize < 1) throw std::runtime_error("Not enough operands for sin");
    double a = stack[--stackSize];
    double result = std::sin(a);
    stack[stackSize++] = result;
    return result;
}