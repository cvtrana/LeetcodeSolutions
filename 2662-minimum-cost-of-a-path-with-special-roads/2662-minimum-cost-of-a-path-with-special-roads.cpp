class Solution {
public:

 int dp[402][402];
int f(vector<vector<int>>&s,int i,int prev,int a1,int b1,int a2,int b2){
    if(i==s.size()){
     if(prev==-1){
         return abs(a2-a1)+abs(b2-b1);
     }
        return abs(a2-s[prev][2])+abs(b2-s[prev][3])+s[prev][4];
     }
     if(dp[i][prev+1]!=-1){return dp[i][prev+1];}
    int nt=f(s,i+1,prev,a1,b1,a2,b2);
    int t=0;
    if(prev==-1){
       t=abs(a1-s[i][0])+abs(b1-s[i][1])+f(s,i+1,i,a1,b1,a2,b2); 
    }
    else{
          t=abs(s[prev][2]-s[i][0])+abs(s[prev][3]-s[i][1])+s[prev][4]+f(s,i+1,i,a1,b1,a2,b2);
    }
    return dp[i][prev+1]=min(nt,t);
    }

int minimumCost(vector<int>& s1, vector<int>&t, vector<vector<int>>&s){
    vector<vector<int>>v=s;
    for(int i=0;i<s.size();i++){
        v.push_back(s[i]);
    }
    memset(dp,-1,sizeof(dp));
    return f(v,0,-1,s1[0],s1[1],t[0],t[1]);
    
}
};