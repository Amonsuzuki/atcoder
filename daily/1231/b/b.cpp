#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	cin >> n;
	if (0 <= n && n < 10)
		cout << "000" << n;
	else if (10 <= n && n < 100)
		cout << "00" << n;
	else if (100 <= n && n < 1000)
		cout << "0" << n;
	else if (1000 <= n && n < 10000)
		cout << n;
}


