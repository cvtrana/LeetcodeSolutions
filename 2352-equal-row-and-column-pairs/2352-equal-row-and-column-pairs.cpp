class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        // Number to store the count of equal pairs.
        int ans = 0;
        map<vector<int>, int> mp;
        
        // storing the count of rows in the map
        for (int i = 0; i < grid.size(); i++)
            mp[grid[i]]++;
        
        for (int i = 0; i < grid[0].size(); i++)
        {
            vector<int> v;
           
            for (int j = 0; j < grid.size(); j++)
                v.push_back(grid[j][i]); // traversing the coloumns
            
            ans += mp[v];
        }
        
        return ans;
        
    }
};