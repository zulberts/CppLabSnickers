#include "ConsoleLogger.h"
#include <iostream>

Severity ConsoleLogger::minimumSeverity() const {
	return Severity::Trace;
}

Severity ConsoleLogger::maximumSeverity() const {
	return Severity::Error;
}

void ConsoleLogger::write(const Message& message) {
	std::cout << message.text << std::endl;
}

