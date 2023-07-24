class DSU {
public:
    vector<int> parent, rank;
    DSU(int n){
        parent.resize(n), rank.resize(n);
        for(int i = 0;i < n;i++)
            parent[i] = i, rank[i] = 1;
    }
    int find(int i){
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y){
        int p1 = find(x), p2 = find(y);
        if(p1 != p2){
            if(rank[p1] > rank[p2])
                parent[p2] = p1;
            else if(rank[p2] > rank[p1])
                parent[p1] = p2;
            else 
                parent[p2] = p1, rank[p1]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n = a.size();
        unordered_map<string, int> mp;
        DSU s(n);
        for(int i = 0;i < n;i++){
            for(int j = 1;j < a[i].size();j++){
                string mail = a[i][j];
                if(mp.find(mail) == mp.end()) mp[mail] = i;
                else s.unite(i, mp[mail]);
            }
        }
        vector<string> ans[n];
        for(auto [str, f] : mp){
            int p = s.find(f);
            ans[p].push_back(str);
        }
        vector<vector<string>> res;
        for(int i = 0;i < n;i++){
            if(ans[i].size() == 0) continue;
            sort(ans[i].begin(), ans[i].end());
            vector<string> temp;
            temp.push_back(a[i][0]);
            for(auto str : ans[i]) temp.push_back(str);
            res.push_back(temp);
        }
        return res;
    }
};