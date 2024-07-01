#pragma once
#include <iostream>


class Time
{
private:

    int hours;
    int minutes;
    int seconds;

    void normalize();
    void init(int hours, int minutes, int seconds);

public:

    Time();
    Time(int hours, int minutes, int seconds);
    Time(Time const& t) = default; //konstruk kopiujący
    ~Time() = default; //konstruktor niszczący a właściwie destruktor
    Time& operator=(Time const& t) = default; // operator "przypisania" po prostu pozwala na przypisanie wszystkich cech

    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    int getTotalSeconds() const;

    void addSeconds(int seconds);
    void addMinutes(int minutes);
    void addHours(int hours);

    void setHours(int hours);
    void setMinutes(int minutes);
    void setSeconds(int seconds);

    Time operator+(const Time& t) const noexcept;
    Time operator-(const Time& t) const noexcept;
    void operator+=(Time const& t) noexcept;
    void operator-=(Time const& t) noexcept;
    Time operator+(int sec) const noexcept;
    Time operator+=(int sec) noexcept;
    Time operator-(int sec) const noexcept;
    Time operator-=(int sec) noexcept;
    Time operator*(int factor) const noexcept;
    Time operator*=(int factor) noexcept;
    bool operator>(const Time& t) const;
    bool operator<(const Time& t) const;
    bool operator<=(const Time& t) const;
    bool operator>=(const Time& t) const;
    bool operator==(const Time& t) const;
    bool operator!=(const Time& t) const;

    friend std::ostream& operator<< (std::ostream& os, Time const& t);
    friend std::istream& operator>> (std::istream& is, Time& t);

    Time& operator++();     // pre inkrementacja
    Time operator++(int);   // post inkrementacja
    Time& operator--();     // analogicznie
    Time operator--(int);

    void operator()(int hours, int minutes, int seconds);   //wywołanie funkcji
};
