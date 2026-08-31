#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dfs(vector<vector<int>> &c, int curr, vector<ll> &ans) {
    ll children = 0;
    for(auto child: c[curr])  {
        children += dfs(c, child, ans);
    }

    ans[curr] = children;
    return children + 1LL;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> c(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        c[x].push_back(i);
    }

    vector<ll> ans(n + 1, 0);
    dfs(c, 1, ans);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}