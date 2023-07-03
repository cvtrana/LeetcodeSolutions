class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n),count(n);
        int ans = 0;
        int maxLen = 1;
        for(int i=0;i<n;i++){
            dp[i] = 1;
            count[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && dp[j] + 1 > dp[i]){ 
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if(1 + dp[j] == dp[i]) 
                    count[i] += count[j];
            }
            maxLen = max(maxLen,dp[i]); 
        }
        
        for(int i=0;i<n;i++){
            if(dp[i] == maxLen) 
                ans += count[i];
        }
        return ans;
    }
};