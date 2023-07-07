class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n  = coins.size();
        vector<int> dp(amount+1,0);
        //memset(dp,0,sizeof(dp));
        dp[0] =1;
        // dont count duplicates
        for(int i=0;i<n;i++){
            for(int j = coins[i];j<amount+1;j++){
                if(j-coins[i] >=0){
                    dp[j] += dp[j-coins[i]];
                    
                }
                
            }
        }
        return dp[amount];
        
        
    }
};