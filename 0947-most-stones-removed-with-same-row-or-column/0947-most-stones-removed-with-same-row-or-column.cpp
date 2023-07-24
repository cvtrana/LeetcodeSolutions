class Disjointset{
    public:
    vector<int> parent,size;
    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findpar(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u] = findpar(parent[u]);
    }
    
    void unionbysize(int u,int v)
    {
        u = findpar(u);
        v = findpar(v);
        if(u==v)
        {
            return;
        }
        if(size[u] > size[v])
        {
            parent[v] = u;
            size[u] += size[v];
        }
        else
        {
            parent[u] = v;
            size[v] += size[u];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow =0;
        int maxcol = 0;
        map<int,int> m;
        for(auto x:stones){
            maxrow = max(maxrow,x[0]);
            maxcol = max(maxcol,x[1]);
        }
        
        Disjointset ds(maxrow+maxcol+1);
        
        for(auto x:stones)
        {
            int row = x[0];
            int col =  maxrow + x[1]  + 1;
           
            ds.unionbysize(row,col);
            
            m[row] = 1;
            m[col] = 1;
            
            
        }
        int cnt =0;
        for(auto x:m)
        {
            if(ds.parent[x.first]==x.first)
            {
                cnt++;
            }
        }
        
        int ans = (int)stones.size() - cnt;
        return ans;
        
        
        
    }
};