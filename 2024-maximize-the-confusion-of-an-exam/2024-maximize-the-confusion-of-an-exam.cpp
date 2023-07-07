class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int i =0;
        int j =0;
        set<char> s;
        int ans = 0; 
        
        // what should be the termination to check the max length??
        map<char,int> m;
        while(j<n){
            if(answerKey[j]=='T'){
                m['T']++;
            }
            if(answerKey[j]=='F'){
                m['F']++;
            }
            if(m['T'] <= k || m['F'] <= k){
                ans = max(ans,j-i+1);
            }
            else{
                m[answerKey[i]]--;
                i++;
            }
            
            j++;
        }
        return ans;
        
    }
};