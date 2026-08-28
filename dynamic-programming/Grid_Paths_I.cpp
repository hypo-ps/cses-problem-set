#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];

    vector<vector<int>> dp(n, vector<int> (n, 0));
    if(grid[0][0] != '*') dp[0][0] = 1;
    for(int i=1; i<n; i++) {
        if(grid[i][0] != '*') dp[i][0] = dp[i-1][0];
        if(grid[0][i] != '*') dp[0][i] = dp[0][i-1];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            if(grid[i][j] != '*') dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(dp[i][j] >= MOD) dp[i][j] -= MOD;
        }
    }

    cout<<dp[n-1][n-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}