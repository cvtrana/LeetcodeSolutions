class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n =  nums.size();
        int dp[n][n];
        
        for(int gap = 0;gap<nums.size();gap++){
            for(int i=0,j=gap;j<nums.size();j++,i++){
                int maxi = -1e9;
                
                for(int k =i;k<=j;k++){
                    int left = k==i ? 0:dp[i][k-1];
                    int right  = k ==j ?0 : dp[k+1][j];
                    int val = (i==0?1:nums[i-1])*(nums[k])*(j==nums.size()-1?1:nums[j+1]);
                    int total = left +  right  + val;
                    maxi = max(maxi,total);
                    
                    
                    
                }
                dp[i][j] = maxi;
            }
            
            
            
            
            
            
        }
        return dp[0][nums.size()-1];
    }
};