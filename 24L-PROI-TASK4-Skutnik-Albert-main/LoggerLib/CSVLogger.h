#pragma once
#include "Logger.h"

class CSVLogger : public ILoggerChannel {
private:
    std::string filename;
    // metoda potrzebna aby mozliwe bylo wpisywanie logow
    // do pliku csv (inaczej bledy mi wyskakiwaly)
    std::string severityToString(Severity severity) const;
public:
    CSVLogger(const std::string& filename);
    ~CSVLogger();
    Severity minimumSeverity() const override;
    Severity maximumSeverity() const override;
    void write(const Message& message) override;
};
