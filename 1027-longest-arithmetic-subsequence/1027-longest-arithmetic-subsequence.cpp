class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1][2000];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=nums[j]-nums[i]+500; // positive 
                dp[i][diff]=max(dp[i][diff],dp[j][diff]+1);
                ans=max(dp[i][diff],ans);
            }
        }
        return ans+1;

    }
};