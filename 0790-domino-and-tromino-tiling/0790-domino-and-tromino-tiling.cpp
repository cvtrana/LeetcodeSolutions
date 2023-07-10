class Solution {
public:
    long long  mod = 1e9 +7;
    int numTilings(int n) {
        
        // option 1  -- ya toh domino lelo
        // option 2 --- ya toh tromino lelo
        
        // dono ke ways add krdo
        if(n==1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        for(int i=4;i<=n;i++){
            dp[i] = ((dp[i-3])%mod + (2*dp[i-1])%mod)%mod;
        }
        return dp[n];
        
        
    }
};