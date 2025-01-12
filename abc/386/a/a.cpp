#include <bits/stdc++.h>
using namespace std;

struct element {
	int num;
	int count;
};

int main(){
	int a;
	vector<int> bcd(4);

	cin >> a >> bcd[1] >> bcd[2] >> bcd[3];
	vector<element> numset(2, {0, 0});
	numset[0].num = a;
	numset[0].count = 1;
	bool found;
	for (int i = 1; i < 4; i++) {
		found = false;
		for (int j = 0; j < 2; j++) {
			if (bcd[i] == numset[j].num) {
				numset[j].count++;
				found = true;
				break;
			}
		}
		if (!found) {
			numset[1].num = bcd[i];
			numset[1].count = 1;
		}
	}
	if (((numset[0].count == 2) && (numset[1].count == 2)) || ((numset[0].count == 1) && (numset[1].count == 3)) || ((numset[0].count == 3) && (numset[1].count == 1))) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return (0);
}
