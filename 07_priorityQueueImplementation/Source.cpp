#include "priorityQueue.h"


int main() {
    PriorityQueue<char> pq;
    pq.push('a', 2);
    pq.push('c', 1);
    pq.push('d', 3);
    pq.push('5', 0);

    pq.print();
    cout << "Top element: " << pq.top() << endl;
    
    pq.pop();
    cout << "Top element after pop: " << pq.top() << endl;

    pq.clear();
    
    if(pq.empty())
		cout << "Priority Queue is empty" << endl;
	else
		cout << "Priority Queue is not empty" << endl;

    return 0;
}