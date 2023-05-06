class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sum1 = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sum2 = accumulate(bobSizes.begin(), bobSizes.end(), 0); 

        int diff = (sum2 - sum1) / 2; 
        set<int> s; 
        
        for (auto b : bobSizes) {
            s.insert(b);
        }
        
        for (auto a : aliceSizes) {
            int b = a + diff; 
            if (s.count(b)) {
                return {a, b}; 
            }
        }
        
        return {}; 
    }
};