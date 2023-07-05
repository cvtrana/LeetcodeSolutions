class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int zeroCount = 0;
        int longestWindow = 0;

        int i = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            zeroCount += (nums[j] == 0);
                          
            // Shrink the window until the zero counts come under the limit.
            while (zeroCount > 1) {
                zeroCount -= (nums[i] == 0);
                i++;
            }
              
            longestWindow = max(longestWindow, j - i);
        }

        return longestWindow;
    }
};