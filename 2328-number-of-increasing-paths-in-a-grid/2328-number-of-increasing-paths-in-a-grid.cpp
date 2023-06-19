class Solution {
public:
    int dp[1005][1005];
    const int mod = 1e9 +7;
    int dx[4] = {0,1,0,-1}; // all 4 directions
    int dy[4] = {1,0,-1,0};
    int n,m;
    
    bool is_valid(int x,int y){
        if(x >= 0 && x < n && y >= 0 && y < m){
            
            return true;
        }
        return false; // out of boundaries
        
    }
    
    int dfs(int x,int y,vector<vector<int>> &grid){
        
        // base case
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        
        if(x > n || x < 0 || y > m || y < 0){
            return 0; // no such path is possible 
        }
        
        int ans =1; // counting the cell value itself
        
        // traverse all 4 directions
        for(int i=0;i<4;i++){
            int newx = x + dx[i];
            int newy = y + dy[i];
            
            if(is_valid(newx,newy)){
                
                if(grid[newx][newy] > grid[x][y]){ // strictly increasing
                    ans = ((ans)%mod + (dfs(newx,newy,grid))%mod)%mod;
                }
            }
        }
        
        return dp[x][y] =  ans;
        
        
        
    }
    int countPaths(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count  = ((count)%mod + (dfs(i,j,grid))%mod)%mod;
            }
        }
        
        
        return count;
        
        
    }
    // time complexity = o(n*m)
};