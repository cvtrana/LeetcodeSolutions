class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = haystack.find(needle);
        if(i != string::npos)
        {
            return i;
        }
        else 
        return -1;
    }
};