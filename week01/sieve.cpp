#include <iostream>

using namespace std;

bool mark[100005];

int main() {
	int n;
	cin >> n;
	mark[1] = false;
	for (int i = 2; i <= n / i; i++) { // i * i <= n
		if (!mark[i]) { // i is prime
			for (int j = i * i; j <= n; j += i)
				mark[j] = true;
		}
	}

	for (int i = 2; i <= n; i++)
		if (!mark[i])
			cout << i << " ";
	cout << "\n";

	

	return 0;
}