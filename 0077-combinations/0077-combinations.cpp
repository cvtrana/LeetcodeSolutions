class Solution {
public:
    void helper(vector<int>& nums, int k, int index, vector<int>& temp, vector<vector<int>>& ans){

        
          if(index==nums.size()){

              if(temp.size()==k){
                  ans.push_back(temp);
              }
              return ;
          }

          helper(nums, k, index+1, temp, ans);
          temp.push_back(nums[index]);
          helper(nums, k, index+1, temp, ans);
          temp.pop_back();
        



    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> nums;

        for(int i = 1;i<=n;i++){
            nums.push_back(i);
        }

        helper(nums,k,0,temp,ans);
        return ans;
    }
};