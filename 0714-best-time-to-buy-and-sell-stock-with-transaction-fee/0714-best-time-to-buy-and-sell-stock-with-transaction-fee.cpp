class Solution {
public:
    
    // dp
    // states -  dp[index][buy/sell];
    vector<vector<int>> dp;
    int rec(int ind,int buy,vector<int> &prices,int fee){
        
        // base case
        if(ind>=prices.size()){
            return 0;
        }
        
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        
        int profit;
        
        if(buy){
            // toh do choices hai
            profit = max(-prices[ind] + rec(ind+1,0,prices,fee),0 + rec(ind+1,1,prices,fee));
            
        }
        else{
            profit = max(prices[ind]-fee + rec(ind+1,1,prices,fee),0 + rec(ind+1,0,prices,fee));
            
            
        }
        return dp[ind][buy] = profit;
        
        
        
        
        
    }
    int maxProfit(vector<int>& prices,int fee){
        dp = vector<vector<int>> (50005, vector<int>(2, -1));
        int ans = rec(0,1,prices,fee);
        return ans;
        
    }
};