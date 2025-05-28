#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    unordered_set<long long> ng;
    for (long long a = 2; a <= 100000; ++a) {
        long long x = a * a;
        while (x <= n) {
            ng.insert(x);
            x *= a;
	    cout << x << endl;
        }
    }
    cout << n - ng.size() << endl;
}
