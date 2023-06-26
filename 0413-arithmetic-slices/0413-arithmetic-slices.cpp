class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n  = nums.size();
        
        int dp[n];
        memset(dp,0,sizeof(dp));
        int ans =0;
        for(int i=2;i<n;i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i-1]  + 1;
                ans += dp[i];
            }
        }
        return ans;
    }
};