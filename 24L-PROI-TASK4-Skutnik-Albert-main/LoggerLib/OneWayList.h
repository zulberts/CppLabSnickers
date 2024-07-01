#pragma once
#include <iostream>

template<typename T>
class Node {
public:
	T value{};
	Node<T>* next = nullptr; //wskaznik na drugiego noda
	Node(T value); //przechowywana wartosc
};

template<typename T>
class OneWayList
{
public:
	Node<T>* head = nullptr; //wskaznik na pierwszego noda
	OneWayList(); //konstruktor
	~OneWayList(); //destruktor
	void push_front(T value) noexcept; //doklada na poczatek
	void push_back(T value) noexcept; //doklada na koniec
	bool isEmpty() const noexcept; //sprawdza czy pustaa
	void pop_front() noexcept; //usuwa pierwszy
	void print(const std::string& title = "List Content:") const noexcept;

	class Iterator {
	private:
		Node<T>* current = nullptr;
	public:
		Iterator(Node<T>* node); //konstruktor, wskazuje na start
		Iterator& operator++(); // +1
		T& operator*() const; //referencja do wartosci
		bool operator!=(const Iterator& other) const; 
		bool operator==(const Iterator& other) const;
	};
	Iterator begin() const; //poczatek
	Iterator end() const; //koniec
};