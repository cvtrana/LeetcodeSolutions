class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n  = nums.size();
        
        
        int temp = k%(n);
        int ind = n  -temp;
        cout << temp <<" " << ind << endl;
        vector<int> v;
        for(int i=ind;i<n;i++){
            v.push_back(nums[i]);
            
        }
        for(int i=0;i<ind;i++){
            v.push_back(nums[i]);
        }
        nums = v;
        
        
    }
};