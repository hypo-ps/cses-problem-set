#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9 + 5;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.length(), m =b.length();
    // dp[n][m] -> distance between strings of length n and m
    vector<vector<int>> dp(n+1, vector<int> (m + 1, INF));
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) dp[i][0] = i;
    for(int i=1; i<=m; i++) dp[0][i] = i;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
    }

    cout << dp[n][m] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}