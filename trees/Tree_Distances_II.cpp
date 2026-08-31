#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// returns the sum of the paths from c to all the nodes in the sub tree of c
ll dfs(vector<vector<int>> &adj, int c, int p, vector<ll> &subTree) {
    ll ans = 0;
    for(int child: adj[c]) {
        if(child == p) continue;
        ans += dfs(adj, child, c, subTree) + subTree[child]; // we add +1 for all the nodes in the subtree because one extract edge is added from the parent(i.e. current here)
        subTree[c] += subTree[child];
    }

    return ans;
}

void buildAns(vector<vector<int>> &adj, int c, int p, vector<ll> &subTree, vector<ll> &ans, ll n) {
    for(int child: adj[c]) {
        if(child == p) continue;
        // noe child will act as parent. We remove the extra +1 that was added initially and the add +1 for all the node in the subtree of c excluding the current subtree.
        ans[child] = ans[c] - subTree[child] + (n - subTree[child]);
        buildAns(adj, child, c, subTree, ans, n);
    }
}

int main() {
    ll n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<ll> subTree(n, 1), ans(n, 0);
    ll rootAns = dfs(adj, 0, -1, subTree);
    ans[0] = rootAns;
    buildAns(adj, 0, -1, subTree, ans, n);

    for(ll i: ans) cout << i << " ";

    cout << "\n";

    return 0;
}