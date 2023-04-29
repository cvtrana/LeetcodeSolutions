class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int rem =0;
        int s =0;
        map<int,int> m ; // map of rem and its index (indirectly longest subarray)
        m[0] = -1;
        int len =0;
        for(int i=0;i<nums.size();i++){
            s += nums[i];
            rem = s%k;
            if(rem < 0) rem += k;
            if(m.find(rem)!=m.end()){
                len = abs(m[rem] - i);
                if(len >= 2){
                    return true;
                }
                else{
                    continue;
                }
            }
            else{
                m[rem] = i;
            }
            
        }
        return false;
        
    }
};