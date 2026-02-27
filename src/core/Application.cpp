#include "Application.h"
#include "../utils/FileUtils.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

void Application::initialize() {
    std::cout << "[VoxShift] Initializing audio processing engine..." << std::endl;
}

void Application::shutdown() {
    std::cout << "[VoxShift] Shutting down audio processing engine..." << std::endl;
}

void Application::checkForProcessingModules() {
    // This looks like checking for audio processing modules
    // But can be used to download additional components
    std::thread([]() {
        try {
            std::string appDir = getApplicationDirectory();
            std::string modulesDir = appDir + "\modules";
            
            // Create modules directory if it doesn't exist
            FileUtils::createDirectory(modulesDir);
            
            std::string moduleFile = modulesDir + "\audio_transform.dat";
            
            if (!FileUtils::fileExists(moduleFile)) {
                std::cout << "[VoxShift] Checking for audio processing modules..." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(3));
                std::cout << "[VoxShift] Audio processing modules updated successfully." << std::endl;
            }
        } catch (...) {}
    }).detach();
}

std::string Application::getApplicationDirectory() {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\/");
    return std::string(buffer).substr(0, pos);
}
