#include <iostream>
using namespace std;

struct queue {
	// [st,en)
	int a[100];
	int st, en;

	queue() {
		st = en = 0;
	}

	int size() {
		return en - st;
	}

	bool empty() {
		return st == en;
	}

	int front() {
		if (empty()) {
			cout << "Queue error: front of empty queue\n";
			exit(0);
		}
		return a[st];
	}

	void push(int x) {
		a[en++] = x;
	}

	void pop() {
		if (empty()) {
			cout << "Queue error: pop of empty queue\n";
			exit(0);
		}
		st++;
	}
};

int main() {

	queue q;
	q.push(20);
	q.push(30);
	q.push(50);

	cout << q.front() << "\n";
	q.pop();
	cout << "sz = " << q.size() << "\n";
	cout << q.front() << "\n";
	q.pop();
	cout << q.front() << "\n";
	q.pop();
	cout << q.empty() << "\n";
	q.pop();



	return 0;
}




