class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n =  nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans = -1;
        
        for(auto x:m){
            if(x.second>1){
                ans = x.first;
                break;
            }
        }
        return ans;
        
    }
};