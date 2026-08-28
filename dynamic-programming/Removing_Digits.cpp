#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9 + 1;
void solve() {
    int n; cin >> n;
    vector<int> dp(n+1, INF); // min number of ways to reduce n to 0;

    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        int temp = i;
        while(temp) {
            int digit = temp % 10;
            temp /= 10;
            dp[i] = min(dp[i], 1 + dp[i-digit]);
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