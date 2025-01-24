#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, count = 0;

	cin >> a;
	for (int i = 1; i < 10; i++) {
		if (a % i == 0 && a / i < 10 ) {
			if (i * i == a)
				count++;
			else
				count += 1;

			//cout << i << endl;
		}
	}
	cout << 2025 - count * a;
}
