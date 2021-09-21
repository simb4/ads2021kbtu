#include <iostream>
using namespace std;

struct Queue {
	// [st, en)
	int a[1000];
	int st, en;

	Queue() {
		st = en = 0;
	}

	int size() {
		return max(0, en - st);
	}

	int front() {
		if (empty()) {
			cerr << "My error: access front but queue is empty\n";
			exit(0);
		}
		return a[st];
	}

	int back() {
		if (empty()) {
			cerr << "My error: access back but queue is empty\n";
			exit(0);
		}
		return a[en-1];
	}

	bool empty() {
		return st == en;
	}

	void push(int x) {
		a[en++] = x;
	}

	void pop() {
		if (empty()) {
			cerr << "My error: pop from empty queue\n";
			exit(0);
		}
		st++;
	}
};

int main() {

	Queue q;
	q.push(20);
	q.push(30);
	q.push(50);

	cout << q.front() << "\n";
	q.pop();
	cout << "sz = " << q.size() << "\n";
	cout << q.front() << "\n";
	cout << q.back() << "\n";
	q.pop();
	cout << q.front() << "\n";
	q.pop();
	cout << q.empty() << "\n";
	q.pop();



	return 0;
}




