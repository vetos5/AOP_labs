#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

template <typename T>
class Stack {
private:
	T* stack;
	int size;
	int capacity;

public:
	Stack(int capacity = 10) : size(0), capacity(capacity) {
		stack = new T[capacity];
	}

	~Stack() {
		delete[] stack;
	}

	void push(T element) {
		if (size < capacity) {
			stack[size++] = element;
		}
		else {
			cerr << "Stack overflow occured. Couldn't add new element. " << endl;
		}
	}

	bool isEmpty() {
		return size == 0;
	}

	void pop() {
		if (!isEmpty()) {
			--size;
			
		}
		else {
			cerr << "Stack is empty. " << endl;
		}
	}

	T top() {
		if (!isEmpty()) {
			return stack[size - 1];
		}
		else {
			cerr << "Stack is empty. Couldn't get top element. " << endl;
			return T();
		}
	}

	int getSize() {
		return size;
	}

};
