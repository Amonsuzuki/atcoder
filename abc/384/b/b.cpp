#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, R;

	cin >> N >> R;
	vector<int> D(N), A(N);
	for (int i = 0; i < N; i++) {
		cin >> D[i] >> A[i];
		if (D[i] == 1 && 1600 <= R && R < 2800)
			R += A[i];
		else if (D[i] == 2 && 1200 <= R && R < 2400)
			R += A[i];
	}
	cout << R << endl;
	return (0);
}

