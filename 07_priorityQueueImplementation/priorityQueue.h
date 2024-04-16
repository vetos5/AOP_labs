#include <iostream>

using namespace std; 

template<typename T>
class PriorityQueue {
private:
    struct Node {
        T data;
        int priority;
        Node* next;
    };

    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push(const T& value, int priority) {
        Node* newNode = new Node{ value, priority, nullptr };

        if (!head or priority < head->priority) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next && priority >= current->next->priority) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void pop() {
        if (!head) {
            cerr << "Priority queue is empty!" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    const T& top() const {
        if (!head) {
            cerr << "Priority queue is empty!" << endl;
            static T defaultConstructedValue;
            return defaultConstructedValue;
        }
        return head->data;
    }

    bool empty() const {
        return head == nullptr;
    }

    void print() const {
        Node* current = head;
        cout << "Priority Queue: ";
        while (current) {
            cout << "(" << current->data << ", " << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }

    void clear() {
		while (head) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};


