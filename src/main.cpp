#include "Calculator.h"
#include <iostream>

int main() {
    try {
        Calculator calc("/home/rishka/CalculatorProject/config/config.yaml");
        calc.PerformCalculations();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}

