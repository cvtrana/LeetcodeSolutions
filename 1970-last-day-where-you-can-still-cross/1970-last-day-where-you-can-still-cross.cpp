class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    bool is_valid(int x,int y, int row, int col){
        if(x >= 0 && y>=0 && x <row && y<col){
            return true;
        }
        return false; // out of bounds
        
    }
    bool possible(vector<vector<int>> &days,int mid, int row , int col){
        // apply bfs here 
        queue<pair<int,int>> q;
        int vis[row][col];
        memset(vis,0,sizeof(vis));
        
        for(int i=0;i<col;i++){
            if(days[0][i] > mid){
                // then only we can apply bfs
                q.push({0,i});
            }
            
        }
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            if(p.first==row-1){
                return true; // last row mein pohonch jayega
            }
            
            for(int i=0;i<4;i++){
                int newx = p.first + dx[i];
                int newy = p.second + dy[i];
                
                if(is_valid(newx,newy,row,col) && days[newx][newy] >  mid && !vis[newx][newy]){
                    vis[newx][newy] = 1;
                    q.push({newx,newy});
                }
            }
            
            
        }
        
        return false;
        
        
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = cells.size();
        int m = cells[0].size();
        
        vector<vector<int>> days(row,vector<int>(col,0)); // sab land hai
        
        for(int i=0;i<n;i++){
            vector<int> v = cells[i];
            int x = v[0];
            int y = v[1];
            x--;
            y--;
            
            days[x][y] = i+1;
        }
        
        int low = 1;
        int high = 1e5;
        int ans =-1;
        
        while(low <= high){
            int mid = (low+high)/2;
            if(possible(days,mid,row,col)){
                low = mid+1;
                ans =  mid;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
        
    }
};