#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<vector<char>> grid;
vector<vector<bool>> visited;

void dfs(int r, int c) {
    // Boundary + visited check
    if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0' || visited[r][c])
        return;

    visited[r][c] = true;

    // Explore 4 directions: up, down, left, right
    dfs(r+1, c);
    dfs(r-1, c);
    dfs(r, c+1);
    dfs(r, c-1);
}

int numIslands() {
    int count = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '1' && !visited[i][j]) {
                count++;       // Found a new island
                dfs(i, j);     // Mark all connected land
            }
        }
    }
    return count;
}

int main() {
    cin >> m >> n;
    grid.assign(m, vector<char>(n));
    visited.assign(m, vector<bool>(n, false));

    // Input grid
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    cout << numIslands() << endl;
}
