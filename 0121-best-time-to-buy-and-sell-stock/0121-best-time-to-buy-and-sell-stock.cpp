class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // here is the approach two

        // taking in account the minimum element at all positions
        int n = prices.size();
        int mini = prices[0];
        int maxprofit = 0;

        for(int i=1;i<n;i++){
            mini = min(mini,prices[i]);
            maxprofit = max(maxprofit,prices[i] - mini);
        }
        return maxprofit;
        
    }
};