class Solution {
    bool ex(int ind, int openingBracket, string &s, vector<vector<int>> &dp){
        if(ind==s.size()) return (openingBracket==0);

        if(dp[ind][openingBracket]!=-1) return dp[ind][openingBracket];

        bool ans=false;
        if(s[ind]=='*'){
            ans|=ex(ind+1,openingBracket+1,s,dp);
            if(openingBracket) ans|=ex(ind+1,openingBracket-1,s,dp);
            ans|=ex(ind+1,openingBracket,s,dp);
        }else{
            if(s[ind]=='('){
                ans=ex(ind+1,openingBracket+1,s,dp);
            }else{
                if(openingBracket) ans=ex(ind+1,openingBracket-1,s,dp);
            }
        }

        return dp[ind][openingBracket]=ans;
    }

public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),-1));
        return ex(0,0,s,dp);
    }
};