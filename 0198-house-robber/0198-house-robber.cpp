class Solution {
public:
    int dp[101];
    bool taken[101];
    
    int rec(int ind,vector<int> &nums){
        // base case
        if(ind == nums.size()-1){
            if(taken[0]==false){
                return nums[ind];
            }
            else{
                return 0;
            }
            
            
        }
        
        if(ind >= nums.size()){
            return 0;
        }
        
        
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        
        // take
        int take = nums[ind] + rec(ind+2,nums);
        taken[ind] = true;
        taken[ind]  =false;
        
        int nottake = rec(ind + 1,nums);
        
        cout << take <<" " << nottake << endl;
        
        return dp[ind] = max(take,nottake);
        
        
        
        
        
        
        
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        memset(taken,0,sizeof(taken));
        int sum = 0;
        
        int ans = rec(0,nums);
        return ans;
        
        
        
    }
};