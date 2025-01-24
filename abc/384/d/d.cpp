#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	unsigned N;
	unsigned long S;
	cin >> N >> S;

	vector<unsigned long> A(N);
	for(auto& a: A)
		cin >> a;
	const auto sum{reduce(begin(A), end(A))};
	S %= sum;

	A.reserve(2 * N);
	for (unsigned i{}; i < N; i++)
		A.emplace_back(A[i]);
	set<unsigned long> prefix_sum{};
	prefix_sum.emplace();
	for (unsigned long p{}; const auto a: A) {
		p += a;
		prefix_sum.insert(p);
	}
	for (const auto p : prefix_sum) 
		if (prefix_sum.contains(p + S)) {
			cout << "Yes" << endl;
			return (0);
		}
	cout << "No" << endl;
	return (0);
}




