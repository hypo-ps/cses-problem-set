#include <bits/stdc++.h>
using namespace std;

void populateDist(vector<vector<int>> &adj, int curr, int p, vector<int> &dist) {
    for(int child: adj[curr]) {
        if(child == p) continue;
        dist[child] = dist[curr] + 1;
        populateDist(adj, child, curr, dist);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int> dist(n, 0);
    populateDist(adj, 0, -1, dist);


    vector<int> maxDist(n, 0), secMaxDist(n, 0);
    int maxElIdx = max_element(dist.begin(), dist.end()) - dist.begin();
    populateDist(adj, maxElIdx, -1, maxDist);

    int secMaxElIdx = max_element(maxDist.begin(), maxDist.end()) - maxDist.begin();
    populateDist(adj, secMaxElIdx, -1, secMaxDist);

    for(int i=0; i<n; i++) {
        cout << max(maxDist[i], secMaxDist[i]) << " ";
    }

    cout << "\n";
    return 0;
}