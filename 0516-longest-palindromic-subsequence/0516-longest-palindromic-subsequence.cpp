class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n= s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int dif =0;dif<n;dif++) {
            for(int i=0,j=i+dif;j<n;i++,j++){
                if(dif == 0){
                    dp[i][j]=1;
                }
                else if(dif ==1){
                    if(s[i]==s[j]){
                        dp[i][j] = 2;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    if(s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1]+2;
                    }
                    else{
                        dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                    }
                }



            }
        }
        return dp[0][n-1];
     }
};