class Solution {
public:
    
    long long dp[100005][3][4];
    long long  rec(int ind,int rem,int prev,string &s){
        if(rem==0){
            return 1;
        }
        if(ind >=  s.length()){
            if(rem==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][prev][rem]!=-1){
            return dp[ind][prev][rem];
        }
        long long  take=0;
        long long  nottake=0;
        if((prev==2) || (prev != (s[ind]-'0'))){
            take = rec(ind+1,rem-1,s[ind]-'0',s);
        }
        nottake = rec(ind+1,rem,prev,s);
        
        return dp[ind][prev][rem] = (take + nottake);
        
        
    }
    long long numberOfWays(string s) {
        int n  = s.length();
        // I can use a 3d dp here
        memset(dp,-1,sizeof(dp));
        
        long long ans = rec(0,3,2,s);
        return ans;
        
        
        
        
    }
};