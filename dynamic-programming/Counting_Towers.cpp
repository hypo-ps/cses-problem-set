#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 1e6;
    vector<vector<int>> dp(N + 1, vector<int> (2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2; i<=N; i++) {
        dp[i][0] = (dp[i][0] + dp[i-1][1]) % MOD;
        dp[i][0] = (dp[i][0] + (4LL * dp[i - 1][0]) % MOD) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % MOD;
        dp[i][1] = (dp[i][1] + (2LL * dp[i - 1][1]) % MOD) % MOD;
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
    }

    return 0;
}