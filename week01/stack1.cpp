#include <iostream>
using namespace std;

struct stack {
	// [0, n)
	int a[100];
	int n;

	stack() {
		n = 0;
	}

	int size() {
		return n;
	}

	void push(int x) {
		a[n++] = x;
	}

	void pop() {
		if (n == 0) {
			cerr << "Stack error: pop of empty stack\n";
			exit(0);
		}
		n--;
	}

	int top() {
		return a[n-1];
	}
};

int main() {

	stack st;
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




