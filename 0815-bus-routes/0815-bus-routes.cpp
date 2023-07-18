class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target){
            return 0;
        }
       int n =  routes.size();
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            for(auto v:routes[i]){
                m[v].push_back(i);
            }
        }
        
        unordered_map<int,bool> visited;
        unordered_map<int,bool> index;
        queue<pair<int,int>> q;
        // q.push({source,0});
        // visited[source] = true;
        for(auto x:m[source]){
            int ind = x;
            index[ind]=true;
            for(auto c:routes[ind]){
                q.push({c,0});
                visited[c] = true;
                
            }
             
        }
        while(!q.empty()){
            int n = q.size();
            while(n--){
                pair<int,int> p =q.front();
                cout << p.first << endl;
                q.pop();
                
                if(p.first==target){
                    return p.second+1;
                }
                
                for(auto c:m[p.first]){
                    if(!index[c]){
                        for(auto x:routes[c]){
                        if(!visited[x]){
                            q.push({x,p.second+1});
                            visited[x] = true;
                        }
                        index[c] = true;

                    }
                        
                    }
                }
                
              
            }
        }
        return -1;
        
    }
};