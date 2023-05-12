class Solution {
public:
    set<pair<int,int>> s;
    int vis[60004];
    int minReorder(int n, vector<vector<int>>& connections){
        map<int,vector<int>> m;
        for(int i =0;i<connections.size();i++){
            vector<int> b = connections[i];
            m[b[0]].push_back(b[1]);
            s.insert({b[0],b[1]});
            m[b[1]].push_back(b[0]);
        }
        memset(vis,0,sizeof(0));
        queue<int> q;
        q.push(0);
        int cnt=0;
        vis[0]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x:m[node]){
                if(!vis[x]){
                    if(s.count({node,x})){ // nodes that are away from root
                        cnt++;
                    }
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
        return cnt;

       

        
        
    }
};