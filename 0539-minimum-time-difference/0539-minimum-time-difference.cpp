class Solution {
public:
    int getIntTime(const string &x) {
        string s;
        stringstream ss(x);
        int t = 0;
        int ret = 0;
        while(getline(ss, s, ':')) {
            ++t;
            if (t == 1) {
                ret = 60 * stoi(s);
            } else {
                ret += stoi(s);    
            }
        }
        return ret;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> res;
        for (const string &x: timePoints) {
            int ret = getIntTime(x);
            res.push_back(ret);
            res.push_back(ret + 1440);
        }
        sort(begin(res), end(res));
        int ans = INT_MAX;
        for (int i = 0; i < res.size(); ++i) {
            if (i) {
                ans = min(ans, res[i] - res[i - 1]);
            }
        }
        return ans;
    }
};