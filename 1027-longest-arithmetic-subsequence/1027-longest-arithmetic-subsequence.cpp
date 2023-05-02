class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;
        int n =  nums.size();
        if(n<=2){
            return 2;
        }
        unordered_map<int,int> dp[n+1];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];
                int cnt = 1;
                
                // check if answer already present
                
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }
                dp[i][diff] = 1 + cnt;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};