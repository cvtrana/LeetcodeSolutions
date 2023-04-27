class Solution {
public:
    int maxArea(vector<int>& height) {
       int ans = 0, n = height.size();
       int i = 0, j = n-1;
       while(i<j){
           if(height[i]>height[j]){
               ans = max(ans, (j-i)*height[j]);
               j--;
           }
           else{
               ans = max(ans, (j-i)*height[i]);
               i++;
           }
       }
       return ans;
    }
};