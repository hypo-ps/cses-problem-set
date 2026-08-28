#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int roll = 1; roll <= 6; roll++) {
            if (i - roll >= 0) dp[i] = (dp[i] + dp[i - roll]) % MOD;
        }
    }

    cout << dp[n] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}