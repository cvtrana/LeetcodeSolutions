class Solution {
public:
    // by taking xor both the sides we can find arr[1], and others
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans{first};
        for(int x: encoded)
            ans.push_back( first^=x );
        return ans;
    }
};