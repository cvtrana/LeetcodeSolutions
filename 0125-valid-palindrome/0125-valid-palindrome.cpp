class Solution {
public:
    bool isPalindrome(string s) {
       string t;
       for(int i=0;i<s.length();i++){
           if(isalnum(s[i])){
               t+=tolower(s[i]);
           }
       } 
       s=t;
       reverse(s.begin(),s.end());
       if(s==t)
       return true;
       return false;
    }
};