class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.length();
        int l = 0;
        int r = 0;
        int store[256] = {0};
        int maxi =0;
        
        while(r < n){
            store[s[r]]++;
             while(store[s[r]]>1)    
            { 
                store[s[l]]--;   
                l++;         
            }
            maxi = max(maxi,r - l +1);
            r++;
            
            
            
        }
        return maxi;
        
    }
};