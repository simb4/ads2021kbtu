#include <iostream>
using namespace std;

struct Stack {
	// [0, n)
	int a[1000];
	int n;
	Stack() {
		n = 0;
	}

	int size() {
		return n;
	}

	// add new element
	void push(int x) {
		a[n] = x;
		n++;
	}

	// removes last element
	void pop() {
		if (n == 0) {
			cerr << "My error: trying to pop empty stack\n";
			exit(0);
		}
		n--;
	}

	// access last element
	int top() {
		return a[n-1];
	}

};

int main() {

	Stack st;
	st.push(10);
	st.push(20);
	cout << "size = " << st.size() << "\n";
	cout << st.top() << "\n";
	st.pop();
	cout << "size = " << st.size() << "\n";
	cout << st.top() << "\n";
	st.pop();
	st.pop();
	cout << st.top() << "\n";


	return 0;
}




