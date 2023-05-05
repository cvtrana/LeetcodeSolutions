class Solution {
public:
    int dp[501][501];
    int rec(int i,int j,string &word1,string &word2){
        // base case
        if(i < 0){
            return j+1;
            
        }
            
                                                     
        if(j< 0) {
             return i+1;
            
        }
        int ans =  1e9;
           
                                                     
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
                                                     
        if(word1[i]==word2[j]){
            return 0 + rec(i-1,j-1,word1,word2);
            
        }
        else{
            ans =  min({1 + rec(i-1,j,word1,word2),1 + rec(i,j-1,word1,word2),1 + rec(i-1,j-1,word1,word2)});
        }
        
        return dp[i][j] =  ans ;
                                                     
                                                     
        
                                                     
                                                
      
        
    }
    int minDistance(string word1, string word2) {
        int n  = word1.size();
        int m = word2.size();
        
        memset(dp,-1,sizeof(dp));
        
        int ans = rec(n-1,m-1,word1,word2);
        return ans;
        
        
    }
};