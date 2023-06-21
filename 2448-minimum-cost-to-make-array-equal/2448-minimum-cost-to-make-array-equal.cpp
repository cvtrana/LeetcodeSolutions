class Solution {
public:
    long long cal(vector<int> &nums,vector<int> &cost,int x){
        long long ans =0;
        for(int i=0;i<nums.size();i++){
            ans += 1L*abs(nums[i]-x)*cost[i];
        }
        return ans;
    }
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // concept of weighted median
        int n  = nums.size();
        
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        
        sort(v.begin(),v.end());
        
        long long sum = 0;
        long long total = 0;
        long long median;
        
        for(int i=0;i<n;i++){
            sum += v[i].second;
        }
        long long i =0;
        
        while(total < (sum+1)/2 && i<n){ // taking ceil value
            total += v[i].second;
            median = v[i].first;
            i++;
            
        }
        
        long long ans = cal(nums,cost,median);
        return ans;
        
        
        
    }
};