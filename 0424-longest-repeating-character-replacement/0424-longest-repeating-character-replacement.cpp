class Solution {
public:
    int characterReplacement(string s, int k) {
        // think of sliding window approach
        // A - B - A - B 
        int n = s.length();
        int maxi = 0;
        map<char,int> m;
        // len - maxfreq <= k  ---- valid ,    then acquire
        // if len  - maxfreq >k ---  invalid , then release 
        
        int i = 0;
        int j =0;
        m[s[0]]++;
        int maxfreq = m[s[0]];
        while(true){
            bool f1 = false;
            bool f2 = false;
            
            // acquire 
            while((j-i+1) - (maxfreq) <= k && j < n){
                // acquire
                j++;
                m[s[j]]++;
                maxfreq = max(maxfreq,m[s[j]]);
                f1= true;
            }
            
            // release
            while((j-i+1) - maxfreq > k && j < n){
                m[s[i]]--;
                i++;
                f2 = true;
            }
            cout <<  i<<" " << j << endl;
            maxi = max(maxi, (int)j-i);
            
            if(f1==false && f2== false){
                break;
            }
            
        }
        return maxi;
        
    }
    
};