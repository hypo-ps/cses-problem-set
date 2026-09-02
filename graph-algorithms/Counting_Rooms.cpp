#include <bits/stdc++.h>
using namespace std;

const vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(vector<string> &grid, int i, int j) {
    grid[i][j] = '#';
    for(auto dir: dirs) {
        int x = i + dir[0], y = j + dir[1];
        if(x >=0 && y >=0 && x < grid.size() && y < grid[0].length() && grid[x][y] != '#') {
            dfs(grid, x, y);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++ ) {
            if(grid[i][j] != '#') {
                dfs(grid, i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}