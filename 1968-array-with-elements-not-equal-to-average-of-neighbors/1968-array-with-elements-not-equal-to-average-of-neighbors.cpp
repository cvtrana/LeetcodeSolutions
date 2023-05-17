class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // agr mein use sort krlu toh 
        //  small big small big small big small , this arrangement should work
        
        int n =  nums.size();
        sort(nums.begin(),nums.end());
        
        int i =  0;
        int j =  n-1;
        vector<int> ans;
        while(i<=j){
            ans.push_back(nums[i]);
            if(i!=j){
                ans.push_back(nums[j]);
                
            }
            
            i++;
            j--;
        }
        return ans;
            
        
        
    }
};