#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t
	cin >> s >> t;
	vector<int> s_i, t_i;
	for (int i = 0; i < s.size(); i++)
		s_i.push_back(s - 'a');
	for (int i = 0; i < t.size(); i++)
		t_i.push_back(t - 'a');

	for (int i = 1; i < s_i.size(); i++) {
		int key = s_i[i];
		int j = i - 1;
		while (j >= 0 && s_i[j] > key) {
			s_i[j + 1] = s_i[j];
			j--;
		}
		s_i[j + 1] = key;
	}

//reverse
	for (int i = 1; i < t_i.size(); i++) {
		int key = t_i[i];
		int j = i - 1;
		while (j >= 0 && t_i[j] > key) {
			t_i[j + 1] = t_i[j];
			j--;
		}
		t_i[j + 1] = key;
	}

