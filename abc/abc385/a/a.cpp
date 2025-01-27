#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, C, flag;

	cin >> A >> B >> C;
	if ((A + B) == C)
		flag = 1;
	else if ((A + C) == B)
		flag = 1;
	else if ((B + C) == A)
		flag = 1;
	else if ((A == B)&&(B == C))
		flag = 1;
	else
		flag = 0;
	if (flag)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return (0);
}

