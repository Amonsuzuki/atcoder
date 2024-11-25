#include <bits/stdc++.h>
using namespace std;

int main () {
	int N;

	cin >> N;
	vector <int> b(N);
	for (int i = 0; i < N; i++)
		cin >> b[i];

	vector <int> ans(N, -1);
	for (int i = N - 1; i > -1; i--) {
		for (int j = i - 1; j > -1; j--) {
			if (b[i] == b[j]){
				ans[i] = j + 1;
				break;
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
}
