class Solution {
public:
    int dp[1002][1002];
    int rec(int i,int j,string &s1 , string &s2, int &n, int &m)
    {
        if(i>=n && j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>=n){
            return s2[j]-0 + rec(i,j+1,s1,s2,n,m);
        }
        if(j>=m){
            return s1[i]-0 + rec(i+1,j,s1,s2,n,m);
        }
        if(s1[i]==s2[j]){
            return rec(i+1,j+1,s1,s2,n,m);
        }
        
        
        int del = s1[i]-0 + rec(i+1,j,s1,s2,n,m);
        int sec = s2[j]-0 + rec(i,j+1,s1,s2,n,m);
        return dp[i][j] = min(del,sec);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,0,s1,s2,n,m);
        return ans;
        
    }
};