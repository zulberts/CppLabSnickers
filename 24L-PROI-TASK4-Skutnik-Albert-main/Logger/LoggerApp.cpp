#include <iostream>
#include "../LoggerLib/OneWayList.h"
#include "../LoggerLib/Logger.h"
#include "../LoggerLib/ConsoleLogger.h"
#include "../LoggerLib/FileLogger.h"
#include "../LoggerLib/CSVLogger.h"


int main() {
    OneWayList<int> list;
    std::cout << "Integer\n";
    list.push_front(12);
    list.push_front(13);
    list.push_front(14);
    list.print("Initial");
    list.push_back(15);
    list.print("push_back");
    list.pop_front();
    list.print("pop_front");
    list.pop_front();
    list.pop_front();
    list.print("last:");
    list.pop_front();
    list.print("emptying");

    OneWayList<double> list2;
    std::cout << "\nDouble Type\n";
    list2.push_front(13.01);
    list2.push_front(112.03);
    list2.push_front(142.33);
    list2.print("List");
    list2.push_back(150.25);
    list2.print("push_back");
    list2.pop_front();
    list2.print("pop_front");
    list2.pop_front();
    list2.pop_front();
    list2.pop_front();
    list2.print("emptying");

    Logger logger;
    // consolChannel to wskaznik na obiekt typu consoleLogger
    // wskazniki trzeba usuwac aaby nie bylo wyciekow pamieci
    // new przydziela pamiec na stosie, nastepnie zwraca 
    // wskaznik na ten obiekt
    // (dynamiczne uzycie pamieci)
    // dzieki temu mozemy dodac na liste jednokierunkowa
    ConsoleLogger* consoleChannel = new ConsoleLogger();
    logger.addChannel(consoleChannel);
    std::string logFile = "log.txt";
    FileLogger* fileChannel = new FileLogger(logFile);
    logger.addChannel(fileChannel);
    Message messages[] = {
        {"Info message", Severity::Info},
        {"Warning message", Severity::Warn},
        {"Error message", Severity::Error}
    };
    for (const auto& message : messages) {
        logger.log(message);
    }

    CSVLogger* csvChannel = new CSVLogger("log.csv");
    logger.addChannel(csvChannel);
    for (const auto& message : messages) {
        logger.log(message);
    }
    return 0;
}
