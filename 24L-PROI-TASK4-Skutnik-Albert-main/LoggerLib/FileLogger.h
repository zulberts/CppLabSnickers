#pragma once
#include "Logger.h"
#include <string>

class FileLogger : public ILoggerChannel {
private:
    std::string filename;
public:
    FileLogger(const std::string& filename);
    ~FileLogger();
    Severity minimumSeverity() const override;
    Severity maximumSeverity() const override;
    void write(const Message& message) override;
};