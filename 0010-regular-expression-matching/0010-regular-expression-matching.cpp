class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        int dp[n+1][m+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                // pehle cell ho
                if(i==0 && j==0){
                    dp[i][j] = true;
                    
                }
                else if(i==0){
                    dp[i][j] =  false;
                    
                }
                else if(j==0){
                    // isme kuch cases hai
                    char pc = p[i-1];
                    if(pc=='*'){
                        dp[i][j] = dp[i-2][j];
                        
                    }
                    else{
                        dp[i][j] = false;
                    }
                    
                }
                else{
                    // charcter of pattern 
                    char pc = p[i-1];
                    char sc = s[j-1];
                    if(pc =='*'){
                        dp[i][j] = dp[i-2][j];
                        char psc = p[i-2];
                        if(psc=='.' || psc == sc){
                            dp[i][j] = dp[i][j] || dp[i][j-1];
                        }
                        
                    }
                    else if(pc =='.'){
                        dp[i][j] = dp[i-1][j-1];
                        
                    }
                    else if(pc == sc){
                        dp[i][j] = dp[i-1][j-1];
                        
                        
                    }
                    else{
                        dp[i][j] =  false;
                        
                    }
                    
                }
                
            }
        }
        return dp[p.length()][s.length()];
        
        
    }
};