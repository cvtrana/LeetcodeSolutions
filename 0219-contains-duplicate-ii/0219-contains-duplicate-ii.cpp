class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int l = nums.size();
    unordered_map<int,int> m;
    
    for(auto i=0;i<l;i++) {
        if(!m.count(nums[i])) // if element is not present in m
            m[nums[i]] = i;
        else  {
            if(abs(m[nums[i]]-i)<=k) // if the diff is at most k
                return true;
            else
                m[nums[i]] =i;   } }
    return false;   
}
};