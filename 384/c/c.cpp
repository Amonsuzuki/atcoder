#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct key {
	int num;
	string s;
};

int main() {
	vector<key> all(31);
	all[30].num = 0;
	all[30].s = "ABCDE";
	for (int i=0; i<5; i++) {
		cin >> all[i].num;
		all[30].num += all[i].num;
		all[i].s = 'A' + i;
	}
	for (int i=0; i<5; i++) {
		all[25+i].num = all[30].num - all[i].num;
		for (int j=0; j<5; j++) {
			if (i!=j)
				all[25+i].s += all[j].s;
		}
	}
	int idx = 0;
	for (int i=0; i<5; i++) {
		for (int j=i+1; j<5; j++) {
			all[5+idx].num = all[i].num + all[j].num;
			all[15+idx].num = all[30].num - all[5+idx].num;
			all[5+idx].s = all[i].s + all[j].s;
			for (int x=0; x<5; x++) {
				if (x!=i && x!=j)
					all[15+idx].s += all[x].s;
			}
			idx++;
		}
	}
	for (int i=0; i<31; i++) {
		for (int j=i; j<31; j++) {
			if (all[i].num < all[j].num || (all[i].num == all[j].num && all[i].s > all[j].s)) {
				key tmp;
				tmp.num = all[i].num;
				tmp.s = all[i].s;
				all[i].num = all[j].num;
				all[i].s = all[j].s;
				all[j].num = tmp.num;
				all[j].s = tmp.s;
			}
		}
	}
	for (int i=0; i<31; i++) {
		cout << hex << uppercase << all[i].s << endl;
	}
}

