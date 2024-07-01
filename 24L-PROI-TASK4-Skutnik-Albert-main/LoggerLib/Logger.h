#pragma once
#include <string>
#include "OneWayList.h"


enum Severity {
	None,
	Trace,
	Info,
	Warn,
	Error
};

// w struct domyslnie wszystko jest publczne
struct Message {
	std::string text;
	Severity severity;
};

//abstrakcyjna klasa bazowa
//virtual odpowiada za polimorfizm, dzieki temu mozliwe jest aby
//pozwalac wywolac odpowiednia metode w zaleznosci od typu bazowego
class ILoggerChannel {
public:
	// = 0 oznacza ze metoda jest czysto wirtualna
	// wymusza implemtacje w klasach pochodnych
	// polimorfizm i klasa abstrakcyjna w skrocie
	virtual ~ILoggerChannel() {}
	virtual Severity minimumSeverity() const = 0;
	virtual Severity maximumSeverity() const = 0;
	virtual void write(const Message& message) = 0;
};

class Logger
{
private:
	OneWayList<ILoggerChannel*> channels;
public:
	Logger();
	~Logger();
	void addChannel(ILoggerChannel* channel);
	void log(const Message& message);
};

