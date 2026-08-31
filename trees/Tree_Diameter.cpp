#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// int dfs(vector<vector<int>> &tree, int curr, int parent, int &ans) {
//     int maxHeight = 0, secMaxHeight = 0;
//     for(int child: tree[curr]) {
//         if (child == parent) continue;
//         int currHeight = dfs(tree, child, curr, ans);
//         if(currHeight > maxHeight) {
//             secMaxHeight = maxHeight;
//             maxHeight = currHeight;
//         } else if (currHeight > secMaxHeight) {
//             secMaxHeight = currHeight;
//         }

//         ans = max(ans, maxHeight + secMaxHeight);
//     }

//     return maxHeight + 1;
// }

void getDepth(vector<vector<int>> &adj, int curr, int p, int currDepth, int &maxDepth, int &maxDepthEl) {
    if(currDepth > maxDepth) {
        maxDepthEl = curr;
        maxDepth = currDepth;
    }
    for(int child: adj[curr]) {
        if(child == p) continue;
        getDepth(adj, child, curr, currDepth+1, maxDepth, maxDepthEl);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int maxDepthEl = -1, maxDepth = 0;
    getDepth(adj, 0, -1, 0, maxDepth, maxDepthEl);
    maxDepth=0;
    getDepth(adj, maxDepthEl, -1, 0, maxDepth, maxDepthEl);
    cout << maxDepth << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}