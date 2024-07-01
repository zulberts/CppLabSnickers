#pragma once
#include <iostream>
#include <stdexcept>

class Fraction
{
private:
	long long numerator = 0LL;
	long long denominator = 1LL;

	long long gcd(long long p, long long q) const noexcept;
	void normalize() noexcept;
	void init(long long nominator, long long denominator);
public:
	Fraction(long long nominator = 0LL, long long denominator = 1LL);
	Fraction(Fraction const& f) = default;
	~Fraction() = default;
	Fraction& operator=(Fraction const& f) = default;

	long long getNumerator() const noexcept;
	long long getDenominator() const noexcept;

	operator double() const;

	Fraction operator+(Fraction const& f) const noexcept;
	Fraction operator-(Fraction const& f) const noexcept;
	Fraction operator*(Fraction const& f) const noexcept;
	Fraction operator/(Fraction const& f) const;

	void operator+=(Fraction const& f) noexcept;
	void operator-=(Fraction const& f) noexcept;
	void operator*=(Fraction const& f) noexcept;
	void operator/=(Fraction const& f);

	Fraction operator-() const noexcept;

	bool operator<(Fraction const& f) const noexcept;
	bool operator>(Fraction const& f) const noexcept;
	bool operator<=(Fraction const& f) const noexcept;
	bool operator>=(Fraction const& f) const noexcept;
	bool operator==(Fraction const& f) const noexcept;
	bool operator!=(Fraction const& f) const noexcept;

	friend std::ostream& operator<< (std::ostream& os, Fraction const& f);
	friend std::istream& operator>> (std::istream& is, Fraction& f);
};
