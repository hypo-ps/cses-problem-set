#include <bits/stdc++.h> 
using namespace std;

bool dfs(vector<vector<int>> &adj, int curr, int prev, vector<int> &color, vector<int> &p, int &start) {
    color[curr] = 1;
    for(int nei: adj[curr]) {
        if(prev == nei) continue;
        if (color[nei] == 2) continue;

        p[nei] = curr;
        if(color[nei] == 1) {
            start = nei;
            return true;
        }
        if(dfs(adj, nei, curr, color, p, start)) return true;
    }

    color[curr] = 2;
    return false;
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

    vector<int> p(n), color(n, 0);
    int start;
    for(int i=0; i<n; i++) {
        if(color[i] == 0 && dfs(adj, i, -1, color, p, start)) {
            vector<int> ans;
            ans.push_back(start);
            int next = p[start];
            while(next != start) {
                ans.push_back(next);
                next = p[next];
            }
            ans.push_back(start);
            cout << ans.size() << endl;
            for(int i: ans) cout << i + 1 << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" <<endl;
    
    return 0;
}