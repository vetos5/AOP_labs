#include "Stack.h"


int main() {

	runTest();

	Stack<int> newStack;
	newStack.push(1);
	newStack.push(2);
	newStack.push(3);

	
	for (int i = 0; i < 3; i++) {
		cout << "Stack top element: " << newStack.top() << endl;
		cout << "Stack size: " << newStack.getSize() << endl;
		newStack.pop();
	}
	if (newStack.isEmpty()) {
		cout << "Stack is empty." << endl;
		return 0;
	}
	
	
	return 0;
	
}

