class Solution {
public:
    int dp[501];
    int rec(int ind,vector<int>&v,int k){
    if(ind >=v.size()){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int maxi = -1;
    int maxans = -1;
    int len = 0;
    for(int i=ind;i<min((int)v.size(),ind+k);i++)
    {
        len++;
        maxi = max(maxi,v[i]);
        int sum = maxi*len + rec(i+1,v,k);
        maxans  = max(maxans,sum);
   
    }
    return dp[ind] = maxans;

}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        int ans = rec(0,arr,k);
        return ans;
        
    }
};