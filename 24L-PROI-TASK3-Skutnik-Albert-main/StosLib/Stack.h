#pragma once
#include <vector>
#include <iostream>

class Stack
{
private:
	std::vector<int> stack;
	void init() noexcept;
	void init(const std::vector<int>& vec) noexcept;
public:
	//konstruktory
	Stack() noexcept;
	Stack(const std::vector<int>& vec) noexcept;

	// "operations"
	void push(int value) noexcept;
	void pop();
	int top() const;
	bool isEmpty() const noexcept;


	// "overload"
	friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

	Stack operator+(const Stack& s) const noexcept;
	Stack& operator+=(const Stack& s) noexcept;

	int operator[](int index) const;

	bool operator==(const Stack& s) const noexcept;
	bool operator!=(const Stack& s) const noexcept;

	Stack operator*(int value) const noexcept;
	Stack operator/(int value) const;
	Stack& operator*=(int value) noexcept;
	Stack& operator/=(int value);

	//dodatkowe
	int hash() const noexcept;
};

