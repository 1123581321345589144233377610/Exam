#include "Divide.hpp"

Divide::Divide() : Operator("/") {}

double Divide::Evaluate(double* stack, int& stackSize) const {
    if (stackSize < 2) throw std::runtime_error("Not enough operands for division");
    double b = stack[--stackSize];
    double a = stack[--stackSize];
    if (b == 0) throw std::runtime_error("Division by zero");
    double result = a / b;
    stack[stackSize++] = result;
    return result;
}