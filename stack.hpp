#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <forward_list>


template <typename Type>
class stack {
private:
	std::forward_list<Type> list;
	size_t m_size;

public:
	stack() : m_size(0) {}

	bool empty() const;
	size_t size() const;
	Type top() const;
	void push(const Type&);
	Type pop();


};

template <typename T>
bool stack<T>::empty() const {
	return list.empty();
}

template <typename T>
size_t stack<T>::size() const {
	return m_size;
}

template <typename T>
T stack<T>::top() const {
	if (empty()) {
		throw std::runtime_error("Stack is empty\n");
	}
	return list.front();
}

template <typename T>
void stack<T>::push(const T& obj) {
	list.push_front(obj);
	m_size++;
}

template <typename T>
T stack<T>::pop() {
	if(empty()) {
		throw std::runtime_error("Stack is empty\n");
	}
	T copy = std::move(list.front());
	list.pop_front();
	m_size--;
	return copy;
}




#endif
