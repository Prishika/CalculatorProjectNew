#include "Calculator.h"
#include <spdlog/sinks/basic_file_sink.h>
#include <iostream>

Calculator::Calculator(const std::string &configFile) {
    try {
        ConfigReader configReader(configFile);
        std::string logFilePath = configReader.GetLogFilePath();
        std::string logFileName = configReader.GetLogFileName();

        logger = spdlog::basic_logger_mt("basic_logger", logFilePath + "/" + logFileName);
        spdlog::set_default_logger(logger);
    } catch (const std::exception &e) {
        std::cerr << "Error initializing Calculator: " << e.what() << std::endl;
        throw;
    }
}

void Calculator::PerformCalculations() {
    int a = 10;
    int b = 5;

    // Perform calculations
    int addResult = MathFunctions::Add(a, b);
    int subResult = MathFunctions::Subtract(a, b);
    int mulResult = MathFunctions::Multiply(a, b);
    double divResult = MathFunctions::Divide(a, b);

    // Log results
    LogResult("addition", addResult);
    LogResult("subtraction", subResult);
    LogResult("multiplication", mulResult);
    LogResult("division", divResult);
}

void Calculator::LogResult(const std::string &operation, double result) {
    logger->info("Result of {}: {}", operation, result);
}
