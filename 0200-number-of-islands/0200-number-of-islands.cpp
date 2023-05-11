class Solution {
public:
    int vis[302][302];
    int dx[4] = {0,1,-1,0};
    int dy[4] = {1,0,0,-1};
    void dfs(int i,int j,vector<vector<char>>&grid,int n,int m ){
        vis[i][j] = 1;
        for(int k=0;k<4;k++){
            int xx = i + dx[k];
            int yy = j + dy[k];
            if((xx>=0 && xx < n && yy >=0 && yy <m) && !vis[xx][yy] && grid[xx][yy]=='1'){
                
                dfs(xx,yy,grid,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cout << i << " " << j << endl;
                    dfs(i,j,grid,n,m);
                    cnt++;

                    
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout <<vis[i][j] <<" ";
            }
            cout << endl;
        }
        return cnt;

        
    }
};