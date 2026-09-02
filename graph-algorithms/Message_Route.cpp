#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int> p(n), visited(n, 0);
    p[0] = -1;
    queue<int> q;
    visited[0] = 1;
    q.push(0);

    bool found = false;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int curr = q.front();
            q.pop();
            for(int nei: adj[curr]) {
                if(visited[nei]) continue;
                visited[nei] = 1;
                q.push(nei);
                p[nei] = curr;
                if(nei == n-1) {
                    found = true;
                    break;
                }
            }

            if(found) break;
        }
        if(found) break;
    }

    if(!found) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

            int curr = n - 1;
    vector<int> ans;
    ans.push_back(curr);
    while(p[curr] != -1) {
        curr = p[curr];
        ans.push_back(curr);
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i: ans) cout << i + 1 << " ";
    cout << endl;

    return 0;
}