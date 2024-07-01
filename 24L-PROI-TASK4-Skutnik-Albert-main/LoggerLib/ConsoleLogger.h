#pragma once
#include "Logger.h"
// :public oznacza dziedziczenie po kolasie ILoggerChannel
// override zapewnia bezpieczeñstwo polimorfizmu
// oznacza ze jest nadpisem funkcji wirtualnej z klasy bazowej
// Message& oznacza przekazanie przez referencje
// (przez referencje czyli pracujemy na oryginalnym obiekcie
// bez kopiowania jego) uzyte z const powoduje to ze obiekt 
// sie nie zmieni a program bedzie pracowal szybciej
class ConsoleLogger : public ILoggerChannel {
public:
	Severity minimumSeverity() const override;
	Severity maximumSeverity() const override;
	void write(const Message& message) override;
};
