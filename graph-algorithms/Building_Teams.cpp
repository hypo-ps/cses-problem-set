#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<int> &color, int curr) {
    for(int nei: adj[curr]) {

        if(color[nei] == color[curr]) return false;
        if(color[nei] != -1) continue;

        color[nei] = (color[curr] % 2) + 1;
        if (!dfs(adj, color, nei)) return false;
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int> color(n, -1);
    for(int i=0; i<n; i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!dfs(adj, color, i)) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    for(int i: color) cout << i << " ";
    cout << endl;

    return 0;
}