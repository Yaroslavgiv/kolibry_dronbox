#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Logger {
public:
    Logger(const std::string& logFile) : logFile_(logFile) {}

    void log(const std::string& message) {
        std::ofstream file(logFile_, std::ios::app);
        if (!file.is_open()) {
            std::cerr << "Failed to open log file: " << logFile_ << std::endl;
            return;
        }

        std::time_t now = std::time(nullptr);
        file << std::ctime(&now) << ": " << message << std::endl;
    }

private:
    std::string logFile_;
};
