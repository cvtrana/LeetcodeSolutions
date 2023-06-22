class Solution {
public:
    
    // dp
    // states -  dp[index][buy/sell];
    int dp[200005][2][5]; // 3d dp
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
    int maxProfit(vector<int>& prices){
        int k =2;
        memset(dp,-1,sizeof(dp));
        
        int ans = rec(0,1,k,prices);
        return ans;
        
    }
};