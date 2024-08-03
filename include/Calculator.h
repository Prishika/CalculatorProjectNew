#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "MathFunctions.h"
#include "ConfigReader.h"
#include <spdlog/spdlog.h>
#include <memory>
#include <string>

class Calculator {
public:
    Calculator(const std::string &configFile);
    void PerformCalculations();

private:
    void LogResult(const std::string &operation, double result);
    std::shared_ptr<spdlog::logger> logger;
};

#endif // CALCULATOR_H
