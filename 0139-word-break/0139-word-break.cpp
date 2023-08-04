class Solution {
public:
int dp[305];
    int rec(int ind,set<string> st,string s){
        if(ind==s.size())return 1;
        if(dp[ind]!=-1)return dp[ind];
        string temp;
        for(int i = ind;i<s.size();i++)
        {
            temp+=s[i];
            if(st.find(temp)!=st.end()){
                if(rec(i+1,st,s))return dp[ind] = 1;
            }
        }
        return dp[ind]=0;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto x:wordDict){
            st.insert(x);


        }
        memset(dp,-1,sizeof(dp));
        return rec(0,st,s);
    }
};