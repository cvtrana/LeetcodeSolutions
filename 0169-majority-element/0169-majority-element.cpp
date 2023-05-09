class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int maxi = -1;
        int ans  =-2;
        for(auto x:m){
            if(x.second > maxi){
                maxi = x.second;
                ans = x.first;
            }
        }
        return ans;
        
    }
};