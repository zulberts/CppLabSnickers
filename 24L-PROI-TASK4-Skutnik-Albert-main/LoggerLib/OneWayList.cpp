#include "OneWayList.h"
#include "Logger.h"


// zeruje wskaznik na next przy tworzeniu nowego noda
template<typename T>
Node<T>::Node(T value) : value(value), next(nullptr) {}

// tworzy liste i zeruje wskaznik na pierwszego noda
template<typename T>
OneWayList<T>::OneWayList() : head(nullptr) {}

template<typename T>
OneWayList<T>::~OneWayList() {
	while (head != nullptr) {
		pop_front();
	}
}

template<typename T>
void OneWayList<T>::push_front(T value) noexcept{
	Node<T>* NewNode = new Node<T>(value);
	NewNode->next = head;
	head = NewNode;
}

template<typename T>
void OneWayList<T>::push_back(T value) noexcept {
	if (!head) {
		push_front(value);
		return;
	}

	Node<T>* newNode = new Node<T>(value);
	Node<T>* temp = head;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = newNode;
}

template<typename T>
bool OneWayList<T>::isEmpty() const noexcept {
	return head == nullptr;
}

template<typename T>
void OneWayList<T>::pop_front() noexcept {
	if (!head) {
		return;
	}
	Node<T>* temp = head;
	head = head->next;
	delete temp; //usuwamy stary element niepotrzebny
}

template<typename T>
void OneWayList<T>::print(const std::string& title) const noexcept {
	std::cout << title << "\n";
	if (isEmpty()) {
		std::cout << "[Empty List]\n";
		return; //nic nie robi jak psuta
	}

	for (auto it = begin(); it != end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\n";
}

template<typename T>
OneWayList<T>::Iterator::Iterator(Node<T>* node) : current(node) {}

template<typename T>
typename OneWayList<T>::Iterator& OneWayList<T>::Iterator::operator++() {
	if (current) {
		current = current->next;
	}
	return *this;
}

// aktualna wartosc danego noda
template<typename T>
T& OneWayList<T>::Iterator::operator*() const {
	return current->value;
}

template<typename T>
bool OneWayList<T>::Iterator::operator!=(const Iterator& other) const {
	return this->current != other.current;
}

template<typename T>
bool OneWayList<T>::Iterator::operator==(const Iterator& other) const {
	return this->current == other.current;
}

template<typename T>
typename OneWayList<T>::Iterator OneWayList<T>::begin() const {
	return Iterator(head);
}

template<typename T>
typename OneWayList<T>::Iterator OneWayList<T>::end() const {
	return Iterator(nullptr);
}

template class OneWayList<int>;
template class OneWayList<double>;
// klasa abstrakcyjna musi byc podawana przez wskaznik 
// poniewaz przez to ze jest abstrakcyjna nie mozna
// odrazu stworzyc tej klasy od razu
// ponad to jezeli przekazemy przez wskaznik to nie bedziemy pracowac na duzych obiektach
// lista jednokierunkowa dzieki temu bedzie przechowywac wskaznik do danego channelu
// a przez to praca moze byc szybsza
// wskaznik pozwala przechowywac rozne typy klasy ILoggerChannel w jednej liscie
template class OneWayList<ILoggerChannel*>;
