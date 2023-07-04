class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        // use gap method
        
        int x = 0;
        int y = 0;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int len = 0;
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g==0){
                    dp[i][j] = true;
                }
                else if(g==1){
                    if(s[i]==s[j]){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = false;
                    }
                }
                else{
                    if(s[i]!=s[j]){
                        dp[i][j] = false;
                    }
                    else{
                        if(dp[i+1][j-1]==true){
                            dp[i][j] = true;
                        }
                        else{
                            dp[i][j] = false;
                        }
                    }
                }
                if(dp[i][j]){
                    x= i;
                    y=j;
                    
                }
            }
        }
        string ans ="";
        for(int i=x;i<=y;i++){
            ans += s[i];
        }
        return ans;
        
    }
};