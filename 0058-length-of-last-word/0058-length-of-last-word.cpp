class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int count=0;
        int flag=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                flag=1;
                count++;
            }
            if(s[i]==' '&& flag){
                break;
            }
        }return count;

        
    }
};