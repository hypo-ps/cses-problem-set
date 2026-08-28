#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> price(n), page(n);
    for(int i=0; i<n; i++) cin >> price[i];
    for(int i=0; i<n; i++) cin >> page[i];

    vector<int> dp(x + 1, 0); // max pages for cost x.

    for(int i=0; i<n; i++) {
        vector<int> curr = dp;
        for(int j=1; j<=x; j++) {
            if(j - price[i] >=0)
                curr[j] = max(curr[j], page[i] + dp[j - price[i]]);
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