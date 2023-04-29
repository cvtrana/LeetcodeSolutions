class Solution {
public:
    bool dp[1001][1001];
    int countSubstrings(string s) {
        memset(dp,0,sizeof(dp));
        
        // starting from the diagonals
        int cnt= 0;
        
        for(int gap=0;gap<s.length();gap++){
            for(int i=0,j=gap;j<s.length();i++,j++){
                if(gap==0){
                    // all single char is always palindrome
                    dp[i][j] = true;
                }
                else if(gap==1){
                    if(s[i]==s[j]){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if(s[i] == s[j]){
                        if(dp[i+1][j-1]==true){ // middle part should be palindrome
                            dp[i][j] = true;
                        }
                        else{
                            dp[i][j] =false;
                        }
                    }
                }
                
                if(dp[i][j]==true){
                    cnt++;
                    
                }
            }
        }
        return cnt;
        
    }
};