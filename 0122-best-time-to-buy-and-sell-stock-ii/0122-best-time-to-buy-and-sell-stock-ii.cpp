class Solution {
public:
    
    // dp
    // states -  dp[index][buy/sell];
    vector<vector<int>> dp;
    int rec(int ind,int buy,vector<int> &prices){
        
        // base case
        if(ind==prices.size()){
            return 0;
        }
        
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        
        int profit;
        
        if(buy){
            // toh do choices hai
            profit = max(-prices[ind] + rec(ind+1,0,prices),0 + rec(ind+1,1,prices));
            
        }
        else{
            profit = max(prices[ind] + rec(ind+1,1,prices),0 + rec(ind+1,0,prices));
            
            
        }
        return dp[ind][buy] = profit;
        
        
        
        
        
    }
    int maxProfit(vector<int>& prices){
        dp = vector<vector<int>> (40005, vector<int>(2, -1));
        int ans = rec(0,1,prices);
        return ans;
        
    }
};