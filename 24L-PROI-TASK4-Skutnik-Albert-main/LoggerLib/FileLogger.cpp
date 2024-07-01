#include "FileLogger.h"
#include <fstream>

FileLogger::FileLogger(const std::string& filename) : filename(filename) {}

FileLogger::~FileLogger() {
    // Destruktor
}

Severity FileLogger::minimumSeverity() const {
    return Severity::Info;
}

Severity FileLogger::maximumSeverity() const {
    return Severity::Error;
}

void FileLogger::write(const Message& message) {
    std::ofstream file(filename, std::ios::app);
    if (file) {
        file << message.text << std::endl;
    }
    else {
        std::cerr << "Unable to write to file: " << filename << std::endl;
    }
}