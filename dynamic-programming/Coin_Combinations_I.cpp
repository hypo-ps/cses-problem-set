#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(x+ 1, 0);
    dp[0] = 1;
    for(int i=1; i<=x; i++) {
        for(int j=0; j<n; j++) {
            if (i - coins[j] >= 0) dp[i] += dp[i - coins[j]];
            if(dp[i] >= MOD) dp[i] -= MOD;
        }
    }

    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}