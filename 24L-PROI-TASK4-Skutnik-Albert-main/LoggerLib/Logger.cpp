#include "Logger.h"

Logger::Logger() {}

Logger::~Logger() {
    while (!channels.isEmpty()) {
        auto channel = channels.begin();
        delete* channel;
        channels.pop_front();
    }
}

void Logger::addChannel(ILoggerChannel* channel) {
    channels.push_front(channel);
}

void Logger::log(const Message& message) {
    for (auto it = channels.begin(); it != channels.end(); ++it) {
        if ((*it)->minimumSeverity() <= message.severity &&
            (*it)->maximumSeverity() >= message.severity) {
            (*it)->write(message);
        }
    }
}