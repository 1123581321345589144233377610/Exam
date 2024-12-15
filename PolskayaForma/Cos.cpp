#include "Cos.hpp"

Cos::Cos() : Operator("cos") {}

double Cos::Evaluate(double* stack, int& stackSize) const {
    if (stackSize < 1) throw std::runtime_error("Not enough operands for cos");
    double a = stack[--stackSize];
    double result = std::cos(a);
    stack[stackSize++] = result;
    return result;
}