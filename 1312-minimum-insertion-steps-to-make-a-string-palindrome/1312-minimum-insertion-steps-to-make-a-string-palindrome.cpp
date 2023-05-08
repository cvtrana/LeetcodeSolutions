class Solution {
public:
    int minInsertions(string s) {
        // s.length() - longest palindromic string
        
        int n = s.length();
        int dp[501][501];
        for(int gap = 0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j] = 1;
                }
                else if(gap==1){
                    // string of length 2
                    if(s[i]==s[j]){
                        dp[i][j] = 2;
                    }
                    else{
                        dp[i][j] =1;
                    }
                }
                else{
                    
                    if(s[i]==s[j]){
                        // check the middle part
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }
                    else{
                        dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                    }
                }
                
                
                
                
            }
            
        }
        return s.length() - dp[0][s.length()-1];
        
    }
};