#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> curr = dp;
        for (int j = 1; j <= x; j++) {
            if (j - coins[i] >= 0) curr[j] += curr[j - coins[i]];
            if (curr[j] >= MOD) curr[j] -= MOD;
        }
    
        dp = curr;
    }

    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}