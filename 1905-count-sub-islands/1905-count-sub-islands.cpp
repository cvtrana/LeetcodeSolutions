class Solution {
public:
  void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col, vector<pair<int, int>>& v) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || !grid[row][col] || visited[row][col])
      return;
    visited[row][col] = 1;
    v.push_back({ row, col });
    dfs(grid, visited, row, col + 1, v);
    dfs(grid, visited, row, col - 1, v);
    dfs(grid, visited, row + 1, col, v);
    dfs(grid, visited, row - 1, col, v);
  }
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    vector<vector<pair<int, int>>> a;
    int n = grid2.size();
    int m = grid2[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid2[i][j] == 1 && visited[i][j] == 0) {
          vector<pair<int, int>> v;
          dfs(grid2, visited, i, j, v);
          a.push_back(v);
        }
      }
    }
    int count = 0;
    for (auto it : a) {
      bool flag = true;
      for (auto itr : it) {
        if (!grid1[itr.first][itr.second]) {
          flag = false;
          break;
        }
      }
      if (flag) count++;
    }
    return count;
  }
};