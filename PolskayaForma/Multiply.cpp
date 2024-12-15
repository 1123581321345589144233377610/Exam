#include "Multiply.hpp"

Multiply::Multiply() : Operator("*") {}

double Multiply::Evaluate(double* stack, int& stackSize) const {
    if (stackSize < 2) throw std::runtime_error("Not enough operands for multiplication");
    double b = stack[--stackSize];
    double a = stack[--stackSize];
    double result = a * b;
    stack[stackSize++] = result;
    return result;
}