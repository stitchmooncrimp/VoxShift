#pragma once
#include <string>

class Application {
public:
    static void initialize();
    static void shutdown();
    static void checkForProcessingModules();
    static std::string getApplicationDirectory();
};
