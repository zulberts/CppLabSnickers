#include "Stack.h"
#include <stdexcept>

Stack::Stack() noexcept {
	init();
}

//'&' oznacza przekazanie przez referencjê.
Stack::Stack(const std::vector<int>& vec) noexcept {
	init(vec);
}

void Stack::init() noexcept {
	stack.clear();
}

void Stack::init(const std::vector<int>& vec) noexcept {
	stack = vec;
}

void Stack::push(int value) noexcept {
	stack.push_back(value);
}

// Funkcja usuwa ostatni element wektora, jeœli wektor nie jest pusty.
void Stack::pop() {
	if (!stack.empty()) {
		stack.pop_back();
	}
	else {
		throw std::runtime_error("Próba usuniêcia elementu ze stosu pustego");
	}
}

// Funkcja zwraca ostatni element wektora bez jego usuwania.
int Stack::top() const {
	if (!stack.empty()) {
		return stack.back();
	}
	throw std::runtime_error("Próba dostêpu do elementu stosu pustego");
}

bool Stack::isEmpty() const noexcept {
	return stack.empty();
}

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
	for (auto it = stack.stack.rbegin(); it != stack.stack.rend(); ++it) {
		os << *it << " ";
	}
	return os;
}

Stack& Stack::operator+=(const Stack& s) noexcept {
	this->stack.insert(this->stack.end(), s.stack.begin(), s.stack.end());
	return *this;
}

Stack Stack::operator+(const Stack& s) const noexcept {
	Stack NewStack = *this;
	NewStack += s;
	return NewStack;
}

// Operator dostêpu do elementu stosu pod danym indexem.
int Stack::operator[](int index) const {
	if (index < stack.size()) {
		return stack[index];
	}
	throw std::invalid_argument("Indeks poza zakresem stosu");
}

bool Stack::operator==(const Stack& s) const noexcept {
	return this->stack == s.stack;
}

bool Stack::operator!=(const Stack& s) const noexcept {
	return !(*this == s);
}

Stack& Stack::operator*=(int value) noexcept {
	for (int& elem : this->stack) {
		elem *= value;
	}
	return *this;
}


Stack Stack::operator*(int value) const noexcept {
	Stack result = *this;
	result *= value;
	return result;
}

Stack& Stack::operator/=(int value) {
	if (value == 0) {
		throw std::invalid_argument("Próba dzielenia przez zero");
	}
	for (int& elem : this->stack) {
		elem /= value;
	}
	return *this;
}

// Operator / zwraca nowy stos
Stack Stack::operator/(int value) const {
	if (value == 0) {
		throw std::invalid_argument("Próba dzielenia przez zero");
	}
	Stack result = *this;
	result /= value;
	return result;
}

// Funkcja oblicza skrót (hash) stosu.
int Stack::hash() const noexcept {
	int hash_value = 0;
	for (int elem : stack) {
		hash_value = hash_value * 15 + elem;
	}
	return hash_value;
}
