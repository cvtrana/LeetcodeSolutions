class Solution {
public:
    
    // dp
    // states -  dp[index][buy/sell];
    int dp[2000][2][102]; // 3d dp
    int rec(int ind,int buy,int cap ,vector<int> &prices){
        
        // base case
        if(ind==prices.size() || cap==0){
            return 0;
        }
        
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        
        int profit;
        
        if(buy){
            // toh do choices hai
            profit = max(-prices[ind] + rec(ind+1,0,cap ,prices),0 + rec(ind+1,1,cap ,prices));
            
        }
        else{
            profit = max(prices[ind] + rec(ind+1,1,cap-1,prices),0 + rec(ind+1,0,cap, prices));
            
            
        }
        return dp[ind][buy][cap] = profit;
        
        
        
        
        
    }
    int maxProfit(int k ,vector<int>& prices){
        memset(dp,-1,sizeof(dp));
        
        int ans = rec(0,1,k,prices);
        return ans;
        
    }
};