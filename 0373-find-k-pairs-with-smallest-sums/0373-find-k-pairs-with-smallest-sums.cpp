class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto compare = [&](const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] > b[0] + b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);
        vector<vector<int>> res;

        if (nums1.empty() || nums2.empty() || k == 0) {
            return res;
        }

        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({ nums1[i], nums2[0], 0 });
        }

        while (k-- > 0 && !pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            res.push_back({ cur[0], cur[1] });

            if (cur[2] == nums2.size() - 1) {
                continue;
            }

            pq.push({ cur[0], nums2[cur[2] + 1], cur[2] + 1 });
        }

        return res;
    }
};