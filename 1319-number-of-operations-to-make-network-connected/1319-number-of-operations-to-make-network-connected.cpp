class Solution {
public:
    vector<int> g[100005];
    int vis[100005];

    void dfs(int u) {
        vis[u] = 1;
        for(auto v: g[u]) {
            if(!vis[v]) dfs(v);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n > connections.size()+1) return -1; // just return the number if connnected components
        memset(vis, 0, sizeof(vis));
        
        for(auto x: connections) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        
        int ans = 0;
        for(int u=0; u<n; u++) {
            if(!vis[u]) {
                ans++;
                dfs(u);
            }
        }
        return ans-1;
    }
};