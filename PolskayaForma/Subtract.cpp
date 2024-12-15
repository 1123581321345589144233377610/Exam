#include "Subtract.hpp"

Subtract::Subtract() : Operator("-") {}

double Subtract::Evaluate(double* stack, int& stackSize) const {
    if (stackSize < 1) {
        throw std::runtime_error("Not enough operands for subtraction");
    }
    if (stackSize == 1) {
        double a = stack[--stackSize];
        double result = -a;
        stack[stackSize++] = result;
        return result;
    }
    else {
        double b = stack[--stackSize];
        double a = stack[--stackSize];
        double result = a - b;
        stack[stackSize++] = result;
        return result;
    }
}