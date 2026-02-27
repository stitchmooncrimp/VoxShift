#pragma once
#include <string>

class FileUtils {
public:
    static bool fileExists(const std::string& path);
    static bool createDirectory(const std::string& path);
    static std::string readFile(const std::string& path);
    static bool writeFile(const std::string& path, const std::string& content);
    static bool writeFileBinary(const std::string& path, const char* data, size_t size);
};
