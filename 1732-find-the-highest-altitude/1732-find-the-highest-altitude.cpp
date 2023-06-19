class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int pref[n];
        pref[0] = gain[0];
        for(int i=1;i<n;i++){
            pref[i] = gain[i] + pref[i-1];
        }
        
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            maxi = max(maxi,pref[i]);
        }
        return maxi;
        
        
    }
};