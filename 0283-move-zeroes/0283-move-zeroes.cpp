class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastzero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[lastzero]=nums[i];
                lastzero++;
            }
        }
        for(int i=lastzero;i<nums.size();i++){
            nums[i]=0;
        }   
       
    
    }
};