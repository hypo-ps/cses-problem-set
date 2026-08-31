#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    vector<int> ans;
    int i=n, j=m;
    while(i>0 && j>0) {
        if(dp[i][j] == dp[i-1][j]) i--;
        else if(dp[i][j] == dp[i][j-1]) j--;
        else {
            i--; j--;
            ans.push_back(a[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << dp[n][m] << "\n";
    for(int num: ans) cout << num << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}