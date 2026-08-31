// dp[i][j][0/1] = max score when only i to j idxs are prending and player 0 has the first turn

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<ll> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    vector<ll> prefix(n+1, 0);
    for(int i=0; i<n; i++) prefix[i+1] = prefix[i] + v[i];

    vector<vector<pair<ll, ll>>> dp(n, vector<pair<ll, ll>>(n));
    // dp[i][j][0] = max(dp[i+1][j][1] + v[i] , dp[i][j-1][1] + v[j])
    for(int i=n-1; i>=0; i--) {
        for(int j=i; j<n; j++) {
            if(i==j) {
                dp[i][j].first = v[i];
                dp[i][j].second = 0ll;
                continue;
            }
            ll mine = max(v[i] + dp[i+1][j].second, v[j] + dp[i][j-1].second);
            ll his = prefix[j+1] - prefix[i] - mine;

            dp[i][j].first = mine;
            dp[i][j].second = his;
        }
    }

    cout << dp[0][n-1].first << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}