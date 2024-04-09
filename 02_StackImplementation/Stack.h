#pragma once
#include <iostream>
#include <cassert>

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

void runTest() {

	Stack<int> newStack;
	newStack.push(1);
	newStack.push(2);
	newStack.push(3);

	assert(newStack.getSize() == 3);
	assert(newStack.top() == 3);

	newStack.pop();
	assert(newStack.top() == 2);

	assert(!newStack.isEmpty());

	newStack.pop();
	newStack.pop();
	assert(newStack.isEmpty());

	assert(newStack.getSize() == 0);

	cout << "All tests passed. " << endl;

}