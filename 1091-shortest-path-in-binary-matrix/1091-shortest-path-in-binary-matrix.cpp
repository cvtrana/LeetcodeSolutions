class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // simple bfs and its done
       
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> vis(rows,vector<int>(cols,0));
       
        queue<pair<pair<int,int>,int>> q;
       
        if(grid[0][0]!=0 || grid[rows-1][cols-1]!=0) return -1;
        
        q.push({{0,0},0});
      
        vis[0][0] =1;
        
        while(!q.empty()){
        
            int sr = q.front().first.first;
            
            int sc = q.front().first.second;
            
            int distance = q.front().second;
            q.pop();
           
            if(sr==rows-1 and sc== cols-1) return distance+1;
            
            int delrow[] = {1,0,-1,-1,-1,0,1,1};
            int delcol[] = {-1,-1,-1,0,1,1,1,0};
            
            for(int i=0;i<8;i++){
                int drow = sr + delrow[i];
                int dcol = sc + delcol[i];
                if(drow>= 0 && drow<rows && dcol>=0 && dcol<cols && 
                grid[drow][dcol]==0 && vis[drow][dcol]==0){
                    
                    q.push({{drow,dcol},distance+1});
                    vis[drow][dcol]=1;
                }
            }
        }
        return -1;

    }
};
