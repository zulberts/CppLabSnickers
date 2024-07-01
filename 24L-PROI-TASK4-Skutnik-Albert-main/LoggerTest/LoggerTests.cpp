#include "gtest/gtest.h"
#include <fstream>
#include "../LoggerLib/OneWayList.h"
#include "../LoggerLib/Logger.h"
#include "../LoggerLib/ConsoleLogger.h"
#include "../LoggerLib/FileLogger.h"
#include "../LoggerLib/CSVLogger.h"

TEST(LoggerTest, AddChannel) {
    Logger logger;
    ConsoleLogger* consoleChannel = new ConsoleLogger();
    logger.addChannel(consoleChannel);
}

TEST(LoggerTest, LogToConsole) {
    Logger logger;
    ConsoleLogger* consoleChannel = new ConsoleLogger();
    logger.addChannel(consoleChannel);

    Message message = { "Info message", Severity::Info };
    ASSERT_NO_THROW(logger.log(message));
}

TEST(LoggerTest, LogToCSV) {
    const char* csvFile = "test_log.csv";
    // strumien wyjsciowy do zapisu pliku
    // trunc to flaga ktora usuwa cala zawartosc pliku
    std::ofstream clearFile(csvFile, std::ios::trunc);
    clearFile.close();

    Logger logger;
    CSVLogger* csvChannel = new CSVLogger(csvFile);
    logger.addChannel(csvChannel);

    Message infoMessage = { "Info message", Severity::Info };
    Message errorMessage = { "Error message", Severity::Error };

    ASSERT_NO_THROW(logger.log(infoMessage));
    ASSERT_NO_THROW(logger.log(errorMessage));

    std::ifstream infile(csvFile);
    std::string line;
    int count = 0;

    while (std::getline(infile, line)) {
        count++;
    }

    infile.close();
    ASSERT_EQ(count, 2);
}

TEST(LoggerTest, LoggerDestructor) {
    Logger* logger = new Logger();
    ConsoleLogger* consoleChannel = new ConsoleLogger();
    logger->addChannel(consoleChannel);

    ASSERT_NO_THROW(delete logger);
}
