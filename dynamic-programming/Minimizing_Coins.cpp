#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int INF = 1e9 + 1;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    // dp[n][x] = min(dp[n-1][x], 1 + dp[n][x - coins[n]])
    for(int i=1; i<=n; i++) {
        vector<int> curr = dp;
        for(int j=1; j<=x; j++) {
            // take
            if(j - coins[i-1] >= 0) curr[j]= min(curr[j], 1 + curr[j - coins[i-1]]);
        }

        dp = curr;
    }

    if(dp[x] == INF) dp[x] = -1;
    cout << dp[x] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}