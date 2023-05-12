class Solution {
public:
    int vis[20004];
    int path[20004];
    int chk[20004];
    vector<int> ans;
    map<int,vector<int>> m;
    bool dfs(int node){
        vis[node] =1;
        path[node]=1;
        for(auto x:m[node]){
            if(!vis[x]){
                if(dfs(x)){
                    chk[node]=0;
                    return true;
                }

            }
            else if(path[x]){
                chk[node]=0;
                return true;

            }
        }
        path[node]=0;
        chk[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // not a safe state if it contains a cycle (nodes which are in cyc;e)
        // every node that leads to a cylcle is not a safe state
        memset(vis,0,sizeof(vis));
        memset(path,0,sizeof(path));
        for(int i=0;i<graph.size();i++){
            vector<int> b= graph[i];
            for(auto x:b){
                m[i].push_back(x);
            }
        }

        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
               bool a =  dfs(i);
            }
        }
        for(int i=0;i<graph.size();i++){
            if(chk[i]){
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;


        
        
    }
};