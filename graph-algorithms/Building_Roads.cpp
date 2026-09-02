#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);

        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int getParent(int n) {
        if(parent[n] == n) return n;
        return parent[n] = getParent(parent[n]);
    }

    void unionByRank(int a, int b) {
        int pa = getParent(a), pb = getParent(b);
        if(pa == pb) return;

        if(rank[pa] > rank[pb]) parent[pb] = pa;
        else if (rank[pb] > rank[pa]) parent[pa] = pb;
        else {
            parent[pb] = pa;
            rank[pa]++;
        }
    }

    vector<int> getAllParents() {
        unordered_set<int> st;
        vector<int> ans;
        for(int i=1; i<parent.size(); i++){
            int p = getParent(i);
            if(st.find(p) == st.end()) {
                ans.push_back(p);
                st.insert(p);
            }
        }

        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU ds(n+1);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        ds.unionByRank(a, b);
    }

    vector<int> parents = ds.getAllParents();
    cout << parents.size() - 1<< endl;
    for(int i=0; i<parents.size()-1; i++) cout << parents[i] << " " << parents[i+1] << endl;

    return 0;
}