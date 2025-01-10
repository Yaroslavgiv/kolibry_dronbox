#include <iostream>
#include <fstream>
#include <string>
#include <json/json.h>

class ConfigLoader {
public:
    ConfigLoader(const std::string& filepath) : filepath_(filepath) {}

    void loadConfig() {
        std::ifstream file(filepath_);
        if (!file.is_open()) {
            std::cerr << "Failed to open config file: " << filepath_ << std::endl;
            return;
        }

        Json::Value config;
        file >> config;
        std::cout << "Configuration loaded: " << config.toStyledString() << std::endl;
    }

private:
    std::string filepath_;
};