class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n = nums.size();
         int zero = 0;
            for( int i = 0; i<n; i++)
            {
                if(nums[i]==0)
                zero+=1;
            }

            int sum = 0;
            for( int i = 0; i <n; i++)
            {
                sum+= nums[i]; 
            }

            if( (target+sum)%2!=0) return 0;

            int reqsum = (target+sum)/2;
            if(reqsum<0) return 0;  
        

            vector<vector<int>>dp(n+1, vector<int>(reqsum+1, -1));

            for( int i = 0; i < n+1; i++)
            {
                for( int j = 0; j< reqsum+1; j++)
                {
                    if( i==0 ) dp[i][j] = 0;
                    if( j ==0 ) dp[i][j] = 1;
                }
            }

            for( int i = 1; i<n+1; i++)
            {
                for( int j = 1; j<reqsum+1; j++)
                {
                    if(nums[i-1]==0)
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                    else if(nums[i-1] > j) {
                        dp[i][j] = dp[i-1][j];
                    }


                   else 
                    {
                        int pick = dp[i-1][j-nums[i-1]];
                        int notpick = dp[i-1][j];
                        dp[i][j] = (pick + notpick);
                    }
                    
                }
            }

            int ans =  pow(2,zero)*dp[n][reqsum];
            return ans;


         








           }
};