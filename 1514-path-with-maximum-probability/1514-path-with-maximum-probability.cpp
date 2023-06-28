class Solution {
public:

    double ans=0;
    double mn = 1e-5;
    void f(int start, int end, vector<bool> &vis, vector<pair<int,double>> adj[],double sum){

        if(sum<=mn) return;

        if(start==end){
            ans = max(ans,sum);
            return;
        }
        
        vis[start] = true;
        for(auto node: adj[start]){
            
            int child = node.first;
            double p = node.second;
           
            if(vis[child]==false && sum*p>=ans){ // sum*p>=ans this will work same as if we have used dp
               f(child,end,vis,adj,sum*p);
            }
        }
        vis[start] = false;
    }



    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int,double>> adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<bool> vis(n,false);

        f(start,end,vis,adj,1);
        return ans;
    }
};