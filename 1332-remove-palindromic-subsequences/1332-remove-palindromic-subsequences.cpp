class Solution {
public:
    bool isPalindrome(string &s)
    {
        int n=s.size();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s[n-1-i]) return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(s.size()==0) return 0;
        if(isPalindrome(s)) return 1;
        else return 2;
    }
};