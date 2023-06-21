class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            
        }
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        
        
        while(k--){
            pair<int,int> p = pq.top();
            ans.push_back(p.second);
            pq.pop();
            
        }
        return ans;
        
    }
};