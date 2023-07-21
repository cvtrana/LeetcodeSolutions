//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> allpaths;
    int vis[10][10];
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0}; // LRUD
    bool is_valid(int x,  int y, int n){
        if(x >= 0 && x < n && y >=0 && y < n){
            return true;
        }
        return false;
    }
    void dfs(int x,int y,vector<vector<int>>&m,int n,string &paths)
    {
        vis[x][y] = 1;
        // if is reached the end;
        if(x==n-1 && y == n-1)
        {
            allpaths.push_back(paths);
            return;
        }
        // else just make calls on different directions and dont forget to backtrack
        for(int i=0;i<4;i++)
        {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if(is_valid(newx,newy,n) && vis[newx][newy]==0 && m[newx][newy] !=0 )
            {
                if(i==0){
                    paths+='L';
                }
                else if(i==1){
                    paths+='R';
                }
                else if(i==2){
                    paths+='U';
                }
                else if(i==3){
                    paths+='D';
                }
                dfs(newx,newy,m,n,paths);
                paths.pop_back(); // backtrack
                vis[newx][newy] = 0; // backtrack
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        memset(vis,0,sizeof(vis));
        string paths=""; // starting string
        if(m[0][0]==0){
            string invalid= "-1";
            vector<string> b; 
            b.push_back(invalid);
            return b;
        }
        dfs(0,0,m,n,paths);
        if(allpaths.size()==0){
            string notvalid = "-1";
            vector<string> b;
            b.push_back(notvalid);
            return b;
        }
        return allpaths;

    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends