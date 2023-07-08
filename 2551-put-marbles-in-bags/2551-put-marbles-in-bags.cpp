class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long n = weights.size();
        vector<int> cand;
        for(int i=0;i<n-1;i++){
            cand.push_back(weights[i]+weights[i+1]);
        }
        sort(cand.begin(),cand.end());
        
        long long  minsum = 0;
        long long  maxsum = 0;
        
        for(int i =0;i<k-1;i++){
            minsum+=cand[i];
            maxsum += cand[n-2-i];
        }
        return maxsum -  minsum;
        
    }
};