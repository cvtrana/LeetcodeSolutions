
class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& v, vector<vector<int>>& grid, int& cnt){
        cnt++;
        v[x][y]=1;
        if(x>0 && grid[x-1][y]==1 && !v[x-1][y]){
            dfs(x-1, y, v, grid, cnt);
        }
        if(y>0 && grid[x][y-1]==1 && !v[x][y-1]){
            dfs(x, y-1, v, grid, cnt);
        }
        if(x<grid.size()-1 && grid[x+1][y]==1 && !v[x+1][y]){
            dfs(x+1, y, v, grid, cnt);
        }
        if(y<grid[0].size()-1 && grid[x][y+1]==1 && !v[x][y+1]){
            dfs(x, y+1, v, grid, cnt);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>v(grid.size(), vector<int>(grid[0].size(), 0));
        int maxi=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!v[i][j] && grid[i][j]==1){
                    int cnt=0;
                    dfs(i, j, v, grid, cnt);v[i][j]=1;
                    maxi=max(maxi, cnt);
                }
            }
        }
        return maxi;
    }
};