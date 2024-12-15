#include "Add.hpp"

Add::Add() : Operator("+") {}

double Add::Evaluate(double* stack, int& stackSize) const {
    if (stackSize < 2) throw std::runtime_error("Not enough operands for addition");
    double b = stack[--stackSize];
    double a = stack[--stackSize];
    double result = a + b;
    stack[stackSize++] = result;
    return result;
}