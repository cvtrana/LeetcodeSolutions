class Solution {
public:
    int rec(int i,int j,vector<int> &nums)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            return nums[i];
        }
        
        int takei = nums[i] + min(rec(i+2,j,nums),rec(i+1,j-1,nums));
        int takej = nums[j] + min(rec(i+1,j-1,nums),rec(i,j-2,nums));
        
        return max(takei,takej);
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        
        int n =  nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }
        
        int player1 = rec(0,n-1,nums);
        if(sum-player1 > player1)
        {
            return false;
        }
        else
        {
            return true;
        }
        
        
    }
};