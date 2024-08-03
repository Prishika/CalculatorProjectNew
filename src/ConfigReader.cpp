#include "ConfigReader.h"
#include <iostream>

ConfigReader::ConfigReader(const std::string &configFile) {
    try {
        std::cout << "Trying to load config file: " << configFile << std::endl;
        config = YAML::LoadFile(configFile);
        std::cout << "Successfully loaded config file" << std::endl;
    } catch (const YAML::Exception &e) {
        std::cerr << "Error loading configuration file: " << e.what() << std::endl;
        throw;
    }
}

std::string ConfigReader::GetLogFilePath() const {
    return config["log_file_path"].as<std::string>();
}

std::string ConfigReader::GetLogFileName() const {
    return config["log_file_name"].as<std::string>();
}

