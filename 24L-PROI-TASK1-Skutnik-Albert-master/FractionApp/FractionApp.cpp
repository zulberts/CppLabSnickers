#include <iostream>
#include "../FractionLib/Fraction.h"

int main()
{
	Fraction a, b;
	do
	{
		std::cout << "a = ";
		std::cin >> a;
		std::cout << "b = ";
		std::cin >> b;

		if (std::cin)
		{
			std::cout << a << "+" << b << " = " << a + b << std::endl;
			std::cout << a << "-" << b << " = " << a - b << std::endl;
			std::cout << a << "*" << b << " = " << a * b << std::endl;
			std::cout << a << "/" << b << " = " << a / b << std::endl;

			std::cout << a << ">" << b << " = " << (a > b) << std::endl;
			std::cout << a << "<" << b << " = " << (a < b) << std::endl;
			std::cout << a << ">=" << b << " = " << (a >= b) << std::endl;
			std::cout << a << "<=" << b << " = " << (a <= b) << std::endl;
			std::cout << a << "==" << b << " = " << (a == b) << std::endl;
			std::cout << a << "!=" << b << " = " << (a != b) << std::endl;
		}
	} while (std::cin && a != Fraction(0, 1) && b != Fraction(0, 1));
}
