#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dfs(vector<vector<int>> &children, int curr, bool takeAllowed, int p, vector<vector<int>> &dp) {
    if(dp[curr][takeAllowed] != -1) return dp[curr][takeAllowed];
    int sum = 0;
    vector<int> take(children[curr].size(), 0), notTake(children[curr].size(), 0);
    for(int i=0; i<children[curr].size(); i++) {
        int child = children[curr][i];
        if(child == p) continue;
        if (takeAllowed) take[i] = dfs(children, child, false, curr, dp);
        notTake[i] = dfs(children, child, true, curr, dp);
        sum += notTake[i];
    }

    int ans = sum;
    if (takeAllowed) {
        for(int i=0; i<children[curr].size(); i++) {
            if(children[curr][i] == p ) continue;
            ans = max(ans, sum - notTake[i] + take[i] + 1);
        }
    }

    return dp[curr][takeAllowed] = ans;
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> children(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        children[a-1].push_back(b-1);
        children[b-1].push_back(a-1);
    }
    vector<vector<int>> dp(n, vector<int> (2, -1));
    int ans = dfs(children, 0, true, -1, dp);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}