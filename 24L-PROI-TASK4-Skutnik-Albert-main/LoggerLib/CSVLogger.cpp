#include "CSVLogger.h"
#include <fstream>

CSVLogger::CSVLogger(const std::string& filename) : filename(filename) {}

CSVLogger::~CSVLogger() {
    // Destruktor
}

Severity CSVLogger::minimumSeverity() const {
    return Severity::Info;
}

Severity CSVLogger::maximumSeverity() const {
    return Severity::Error;
}

std::string CSVLogger::severityToString(Severity severity) const {
    switch (severity) {
    case Severity::Trace: return "Trace";
    case Severity::Info: return "Info";
    case Severity::Warn: return "Warning";
    case Severity::Error: return "Error";
    default: return "Unknown";
    }
}

void CSVLogger::write(const Message& message) {
    // ofstream - strumien wyjsciowy do pliku
    // ios app - dodawanie na koniec pliku
    // jesli nie istnieje zostanie utworzony plik nowy
    std::ofstream outFile(filename, std::ios::app);
    if (outFile.is_open()) {
        outFile << "\"" << severityToString(message.severity) << "\",\"" << message.text << "\"\n";
    }
    else {
        std::cerr << "Unable to write to file: " << filename << std::endl;
    }
}
