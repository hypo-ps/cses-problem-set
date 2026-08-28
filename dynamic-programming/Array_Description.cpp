#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int func(vector<int> &nums, int idx, int prev, int m, vector<vector<int>> &dp) {
    if(idx == nums.size()) return 1;
    if(dp[idx][prev] != -1) return dp[idx][prev];
    if(nums[idx] != 0) {
        if (abs(prev - nums[idx]) > 1) return dp[idx][prev] = 0;
        return dp[idx][prev] = func(nums, idx + 1, nums[idx], m, dp);
    }

    int ans = 0;
    for(int i = -1; i<=1; i++) {
        if(prev + i > 0 && prev + i <= m)
            ans += func(nums, idx + 1, prev + i, m, dp);
        if(ans >= MOD) ans -= MOD;
    }

    return dp[idx][prev] = ans;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];

    vector<vector<int>> dp(n, vector<int> (m+1, -1));

    int ans = 0;
    if (nums[0] != 0)
        ans = func(nums, 1, nums[0], m, dp);
    else {
        for(int i=1; i<=m; i++) {
            ans += func(nums, 1, i, m, dp);
            if (ans >= MOD) ans -= MOD;
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}