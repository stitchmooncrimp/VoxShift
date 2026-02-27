#include "FileUtils.h"
#include <filesystem>
#include <fstream>
#include <sstream>

bool FileUtils::fileExists(const std::string& path) {
    return std::filesystem::exists(path);
}

bool FileUtils::createDirectory(const std::string& path) {
    return std::filesystem::create_directories(path);
}

std::string FileUtils::readFile(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

bool FileUtils::writeFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (file.is_open()) {
        file << content;
        file.close();
        return true;
    }
    return false;
}

bool FileUtils::writeFileBinary(const std::string& path, const char* data, size_t size) {
    std::ofstream file(path, std::ios::binary);
    if (file.is_open()) {
        file.write(data, size);
        file.close();
        return true;
    }
    return false;
}
