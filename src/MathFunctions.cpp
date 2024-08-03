#include "MathFunctions.h"
#include <stdexcept>

int MathFunctions::Add(int a, int b) {
    return a + b;
}

int MathFunctions::Subtract(int a, int b) {
    return a - b;
}

int MathFunctions::Multiply(int a, int b) {
    return a * b;
}

double MathFunctions::Divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("Division by zero is not allowed.");
    }
    return static_cast<double>(a) / b;
}

