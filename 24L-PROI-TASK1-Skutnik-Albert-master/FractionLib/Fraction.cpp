#include <iostream>
#include <iomanip>
#include <cmath>
#include "Fraction.h"

long long Fraction::gcd(long long p, long long q) const noexcept {
	while (q != 0) {
		long long temp = q;
		q = p % q;
		p = temp;
	}
	return p;
}

void Fraction::normalize() noexcept {
	if (numerator != 0) {
		long long divider = gcd(abs(numerator), abs(denominator));
		numerator /= divider;
		denominator /= divider;

		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}
	else {
		denominator = 1;
	}
}

void Fraction::init(long long numerator, long long denominator)
{
	if (denominator == 0)
		throw std::invalid_argument("Denominator cannot be zero.");
	this->numerator = numerator;
	this->denominator = denominator;
	this->normalize();
}

Fraction::Fraction(long long numerator, long long denominator)
{
	init(numerator, denominator);
}

long long Fraction::getNumerator() const noexcept
{
	return numerator;
}

long long Fraction::getDenominator() const noexcept
{
	return denominator;
}

Fraction::operator double() const
{
	double numeratordouble = static_cast<double>(numerator);
	double denumeratordouble = static_cast<double>(denominator);
	return numeratordouble / denumeratordouble;
}

Fraction Fraction::operator+(Fraction const& f) const noexcept
{
	Fraction result = *this;
	result += f;
	return result;
}

Fraction Fraction::operator-(Fraction const& f) const noexcept
{
	Fraction result = *this;
	result -= f;
	return result;
}

Fraction Fraction::operator*(Fraction const& f) const noexcept
{
	Fraction result = *this;
	result *= f;
	return result;
}

Fraction Fraction::operator/(Fraction const& f) const
{
	Fraction res(*this);
	res /= f;
	return res;
}

void Fraction::operator+=(Fraction const& f) noexcept
{
	long long commonDenominator = denominator * f.denominator;
	numerator = numerator * f.denominator + f.numerator * denominator;
	denominator = commonDenominator;
	normalize();
}

void Fraction::operator-=(Fraction const& f) noexcept
{
	long long commonDenominator = denominator * f.denominator;
	numerator = numerator * f.denominator - f.numerator * denominator;
	denominator = commonDenominator;
	normalize();
}

void Fraction::operator*=(Fraction const& f) noexcept
{
	long long d1 = gcd(numerator, f.denominator);
	long long d2 = gcd(denominator, f.numerator);
	numerator = (numerator / d1) * (f.numerator / d2);
	denominator = (denominator / d2) * (f.denominator / d1);
	normalize();
}

void Fraction::operator/=(Fraction const& f)
{
	if (f.numerator == 0LL)
		throw std::domain_error("Division by zero.");
	long long d1 = gcd(numerator, f.numerator);
	long long d2 = gcd(denominator, f.denominator);
	numerator = (numerator / d1) * (f.denominator / d2);
	denominator = (denominator / d2) * (f.numerator / d1);
	normalize();
}

Fraction Fraction::operator-() const noexcept
{
	return Fraction(-numerator, denominator);
}

bool Fraction::operator<(Fraction const& f) const noexcept
{
	return numerator * f.getDenominator() < f.getNumerator() * denominator;
}

bool Fraction::operator>(Fraction const& f) const noexcept
{
	return numerator * f.getDenominator() > f.getNumerator() * denominator;
}

bool Fraction::operator<=(Fraction const& f) const noexcept
{
	return *this < f || *this == f;
}

bool Fraction::operator>=(Fraction const& f) const noexcept
{
	return *this > f || *this == f;
}

bool Fraction::operator==(Fraction const& f) const noexcept
{
	return numerator == f.numerator && denominator == f.denominator;
}

bool Fraction::operator!=(Fraction const& f) const noexcept
{
	return !(*this == f);
}

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
	if (f.denominator == 1) {
		os << f.numerator;
	}
	else {
		os << f.numerator << "/" << f.denominator;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Fraction& f)
{
	is >> f.numerator;
	f.denominator = 1;

	char c = is.get();
	if (c == '/')
		is >> f.denominator;
	else
		is.unget();
	f.init(f.numerator, f.denominator);
	return is;
}
