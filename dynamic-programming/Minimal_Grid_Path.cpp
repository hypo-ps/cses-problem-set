#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<string>> dp(3005, vector<string> (3005, ""));

string func(vector<string> &grid, int i, int j) {
    if(i == grid.size() || j == grid[0].size()) return "";

    if(dp[i][j] != "") return dp[i][j];

    if(i == grid.size()-1) return dp[i][j] = grid[i][j] + func(grid, i, j+1);
    if(j == grid[0].size()-1)
        return dp[i][j] = grid[i][j] + func(grid, i + 1, j);

    if(grid[i+1][j] < grid[i][j+1])
        return dp[i][j] = grid[i][j] + func(grid, i + 1, j);
    if (grid[i + 1][j] > grid[i][j + 1])
        return dp[i][j] = grid[i][j] + func(grid, i, j + 1);

    return dp[i][j] =
               grid[i][j] + min(func(grid, i + 1, j), func(grid, i, j + 1));
}

void solve() {
    int n; cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; i++) cin >> grid[i];

    cout<< func(grid, 0, 0) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}