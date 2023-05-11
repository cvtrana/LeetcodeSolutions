class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0 ,0,1,-1};
    int vis[101][101];
    int cnt =0;
    void  dfs(int i, int j , vector<vector<int>> &grid){
        if(i <0 || i >grid.size() || j<0 || j>grid[0].size()){
            return;
        }
        
        
        // check directions and increase cnt accordingly
        int cell =0 ;
        for(int k=0;k<4;k++){
            int x = i + dx[k];
            int y = j + dy[k];
            //cout << x << " " << y << endl;
            if(x >= 0 && x < grid.size() && y >=0 && y < grid[0].size()){
                if(grid[x][y]==1){
                    cell++;
                    
                }
                
            }
        }
        //cout << cell << endl;
        cnt += 4- cell;
        //cout << cnt << endl;
        //cout << cell << endl;
        
        for(int k =0 ;k<4;k++){
             int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && x < grid.size() && y >=0 && y < grid[0].size() && vis[i][j]==0){
                vis[i][j] =1;
                dfs(x,y,grid);
                
                

                
            }
            
        }
        
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n =  grid.size();
        int m =  grid[0].size();
        memset(vis,0,sizeof(vis));
        
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vis[i][j] = 1;
                    // call dfs
                 dfs(i,j,grid);
                }
            }
        }
        return cnt ;
        
        
    }
};