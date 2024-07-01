#include "Time.h"

void Time::normalize()      //zmieniłem normalizacje aby podczas dodawania i odejmowania samoczynnie wszystko normalizowała
{
    if (seconds < 0)
    {
        int deficyt = abs(seconds) / 60 + 1;
        minutes -= deficyt;
        seconds += deficyt * 60;
    }
    if (minutes < 0)
    {
        int deficyt = abs(minutes) / 60 + 1;
        hours -= deficyt;
        minutes += deficyt * 60;
    }
    if (hours < 0)
    {
        hours = 0;
    }
    minutes += seconds / 60;
    seconds %= 60;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::init(int hours, int minutes, int seconds) //zeruje tutaj ponieważ nie chce aby dało się ustawić błędny czas
{
    this->hours = hours < 0 ? 0 : hours; // warunek ? true : false
    this->minutes = minutes < 0 ? 0 : minutes;
    this->seconds = seconds < 0 ? 0 : seconds;
    normalize();
}

Time::Time() {
    init(0, 0, 0);
}

Time::Time(int hours, int minutes, int seconds){
    init(hours, minutes, seconds);
}

int Time::getHours() const {
    return hours;
}

int Time::getMinutes() const {
    return minutes;
}

int Time::getSeconds() const {
    return seconds;
}

void Time::setHours(int hours)
{
    if (hours < 0) {
        hours = 0;
    }
    this->hours = hours;
    normalize();
}

void Time::setMinutes(int minutes)
{
    if (minutes < 0)
    {
        minutes = 0;
    }
    this->minutes = minutes;
    normalize();
}

void Time::setSeconds(int seconds)
{
    if (seconds < 0)
    {
        seconds = 0;
    }
    this->seconds = seconds;
    normalize();
}

int Time::getTotalSeconds() const
{
    return (this->hours * 3600 + this->minutes * 60 + this->seconds);
}

void Time::addSeconds(int seconds)
{
    this->seconds += seconds;
    normalize();
}

void Time::addMinutes(int minutes)
{
    this->minutes += minutes;
    normalize();
}

void Time::addHours(int hours)
{
    this->hours += hours;
    normalize();
}

void Time::operator+=(Time const &t) noexcept
{
    this->addSeconds(t.getTotalSeconds());
}

Time Time::operator+(Time const& t) const noexcept
//const Time &t sprawia że nie zmieni obiektu t przekazywanego do funkcji
//& przed t oznacza przekazanie przez referencje i sprawia ze pracujemy odrazu na obiekcie t, ale nie zmieniamy go, dzieki temu program jest bardziej wydajny
// const noexcept na koncu oznacza ze nie zmienia obiektu na ktorym działamy, a noexcpet sprawia ze prgram nie musi sprawdzac wyjątków
{
    Time result = *this;
    result += t;
    return result;
}

void Time::operator-=(Time const &t) noexcept
{
    int totalSeconds = getTotalSeconds() - t.getTotalSeconds();
    if (totalSeconds < 0)
    {
        operator()(0, 0, 0);
    }
    else
    {
        operator()(0, 0, totalSeconds);
    }
}

Time Time::operator-(Time const& t) const noexcept
{
    Time result = *this;
    result -= t;
    return result;
}

std::ostream &operator<<(std::ostream &os, const Time& t)
{
    os << t.getHours() << ":" << t.getMinutes() << ":" << t.getSeconds();
    return os;
}

std::istream &operator>>(std::istream &is, Time &t)
{
    int hours, minutes, seconds;
    char colon1, colon2;
    bool errorOcurred = false;
    if (!(is >> hours))
    {
        errorOcurred = true;
    }

    colon1 = is.get();
    if (colon1 != ':' || !(is >> minutes) || minutes < 0)
    {
        errorOcurred = true;
    }
    else
    {
        colon2 = is.get();
        if (colon2 != ':' || !(is >> seconds) || seconds < 0)
        {
            errorOcurred = true;
        }
    }
    if (errorOcurred){
        t.operator()(0, 0, 0);
    }
    else{
        t.operator()(hours, minutes, seconds);
    }
    return is;
}

bool Time::operator<(const Time& t) const
{
    if (hours == t.hours)
    {
        if (minutes == t.minutes)
        {
            return seconds < t.seconds;
        }
        return minutes < t.minutes;
    }
    return hours < t.hours;
}

bool Time::operator>(const Time &t) const
{
    if (hours == t.hours)
    {
        if (minutes == t.minutes)
        {
            return seconds > t.seconds;
        }
        return minutes > t.minutes;
    }
    return hours > t.hours;
}

bool Time::operator<=(const Time& t) const
{
    return !(*this > t);
}

bool Time::operator>=(const Time& t) const
{
    return !(*this < t);
}

bool Time::operator==(const Time& t) const
{
    return hours == t.hours && minutes == t.minutes && seconds == t.seconds;
}

bool Time::operator!=(const Time& t) const
{
    return !(*this == t);
}

Time Time::operator+=(int sec) noexcept
{
    this->addSeconds(sec);
    return *this;
}

Time Time::operator+(int sec) const noexcept
{
    Time result = *this;
    result += sec;
    return result;
}

Time Time::operator-=(int sec) noexcept
{
    this->addSeconds(-sec);
    return *this;
}

Time Time::operator-(int sec) const noexcept
{
    Time result = *this;
    result -= sec;
    return result;
}

Time Time::operator*=(int factor) noexcept
{
    if (factor < 0)
    {
        factor = 0;
    }
    int totalSeconds = getTotalSeconds() * factor;
    operator()(0, 0, totalSeconds);
    return *this;
}

Time Time::operator*(int factor) const noexcept
{
    Time result = *this;
    result *= factor;
    return result;
}

Time& Time::operator++() {
    addSeconds(1);
    return *this;
}

Time Time::operator++(int)      // int tutaj używany jest tylko żeby rozróżnić post i pre inkrementacje
{                               // jednak w programie i tak zapiszemy to ++x lub x++
    Time temporary = *this;
    ++(*this);
    return temporary;
}

Time &Time::operator--()
{
    if (getTotalSeconds() == 0)
    {
        return *this;
    }
    addSeconds(-1);
    return *this;
}

Time Time::operator--(int)
{
    Time temporary = *this;
    --(*this);
    return temporary;
}

void Time::operator()(int hours, int minutes, int seconds)
{
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}