class Solution {
public:
    int dp[2501];
    int rec(int level,vector<int> &nums){
        if(level < 0) {
            return 0;
        }
        
        if(dp[level]!=-1)return dp[level];
        
        int ans =1;
        for(int i=0;i<level;i++){
            if(nums[i] < nums[level]){
                ans =  max(ans,1 + rec(i,nums));
            }
        }
        return dp[level] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int best =0;
        for(int i=0;i<nums.size();i++){
            best = max(best,rec(i,nums));
            
            
        }
        return best;
        
    }
};