class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        map<int,int> m;
        
        int n = arr.size();
        int result =0;
        
        
        for(int i=0;i<n;i++){
            int tofind = arr[i] - difference;
            
            int len = m[tofind];
            m[arr[i]] = 1 + len;
             result = max(result,m[arr[i]]);
        }
              return result;

        
    }
};