#include <bits/stdc++.h>
using namespace std;

struct known {
	int num;
	int count;
};

int main() {
	int N, max, flag;

	cin >> N;
	vector<int> H(N);
	vector<known> KN(N);
	flag = 0;
	for (int i = 0; i < N; i++)
		cin >> H(i);
		for (int j = 0; j < i; j++) {
			if (H(i) == known[j].num)
				flag = 1;
				break;
		}
		if (!flag)





	

