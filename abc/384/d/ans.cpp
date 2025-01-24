#include <iostream>
#include <numeric>
#include <set>
#include <vector>
int main() {
    using namespace std;
    unsigned N;
    unsigned long S;
    cin >> N >> S;
    vector<unsigned long> A(N);
    for (auto& a : A)
        cin >> a;
    // 0 <= S < X に帰着
    const auto sum{reduce(begin(A), end(A))};
    S %= sum;
    // A の長さを倍にする
    A.reserve(2 * N);
    for (unsigned i{}; i < N; ++i)
        A.emplace_back(A[i]);
    // 累積和を計算
    set<unsigned long> prefix_sum{};
    prefix_sum.emplace();
    for (unsigned long p{}; const auto a : A) {
        p += a;
        prefix_sum.insert(p);
    }
    // 累積和の要素 p について p + S が含まれているか判定
    for (const auto p : prefix_sum)
        if (prefix_sum.contains(p + S)) {
            cout << "Yes" << endl;
            return 0;
        }
    cout << "No" << endl;
    return 0;
}

