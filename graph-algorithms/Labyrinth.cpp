#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
vector<char> dirChars = {'U', 'D', 'R', 'L'};

void bfs(vector<vector<char>> &grid, int x, int y) {
    queue<pair<int, int>> q;
    vector<vector<pair<pair<int, int>, char>>> parent(grid.size(), vector<pair<pair<int, int>, char>>(grid[0].size()));
    parent[x][y] = {{-1, -1}, '0'};
    q.push({x, y});
    grid[x][y] = '#';
    pair<int, int> last = {-1, -1};
    bool found = false;
    while(!q.empty()) {
        auto curr = q.front();
        q.pop();
        int i = curr.first, j = curr.second;
        for(int k=0; k<dirs.size(); k++) {
            int ni = i + dirs[k][0], nj = j + dirs[k][1];
            if(ni >= 0 && nj >= 0 && ni < grid.size() && nj < grid[0].size() && grid[ni][nj] != '#') {
                parent[ni][nj] = {{i, j}, dirChars[k]};
                if (grid[ni][nj] == 'B') {
                    last = {ni, nj};
                    found = true;
                    break;
                }
                grid[ni][nj] = '#';
                q.push({ni, nj});
            }
        }

        if(found) break;
    }

    if(last.first == -1) {
        cout << "NO" << endl;
        return;
    }

    string path = "";
    while(parent[last.first][last.second].second != '0') {
        path += parent[last.first][last.second].second;
        last = parent[last.first][last.second].first;
    }

    reverse(path.begin(), path.end());
    cout << "YES" << endl << path.length() << endl << path << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    int x, y;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                x = i; y = j;
            }
        }
    }

    bfs(grid, x, y);

    return 0;
}