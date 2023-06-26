class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n  = nums.size();
        
        int ans =0;
        map<long long,int> arr[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long   diff = (long long)nums[i] - nums[j];
                
                // find this diff in the prev one(that is in j)
                auto it = arr[j].find(diff);
                
                long long cnt_at_j = (it== arr[j].end()?0:it->second);
                arr[i][diff] += cnt_at_j+1;
                ans += cnt_at_j;
             }
        }
        return ans;
        
        
        
    }
};