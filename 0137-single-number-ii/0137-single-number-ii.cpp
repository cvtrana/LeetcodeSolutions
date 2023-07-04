class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // brute force 
        
        int n =  nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        
        for(auto x:m){
            if(x.second <3){
                return x.first;
            }
        }
        return -1;
        
    }
};