class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        // find the LIS nD LDS , then sum at each index
        
         int n  = nums.size();
        vector<int> inc(n,1);
        vector<int> dec(n,1);
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[i] >   nums[prev]){
                    inc[i] = max(inc[i],1 + inc[prev]);
                }
            }
            
        }
        
        // similarly , calculate the LDS
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                if(nums[i] > nums[j]){
                    dec[i] = max(dec[i],1 + dec[j]);
                }
            }
        }
       
        int maxi  =0;
        for(int i=0;i<n;i++){
            cout << inc[i] + dec[i] -1 << " ";
            if(inc[i]>1 && dec[i]>1){
                maxi =  max(maxi,inc[i] + dec[i] - 1);
                
            }
        }
        int ans = nums.size() - maxi;
        return ans;
       
        
    }
};