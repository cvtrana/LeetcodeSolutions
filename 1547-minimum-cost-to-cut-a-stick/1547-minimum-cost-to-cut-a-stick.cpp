class Solution
{
public:
    vector<vector<int>> dp;
    int recursion(int l, int r, int left, int right, vector<int> &cuts)
    {
        if (r < l) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int answer = INT_MAX;
        for (int i = l; i <= r; i++)
        {
            int length = (right - left) ;
            int current = length + recursion(l, i - 1, left, cuts[i], cuts) + recursion(i + 1, r, cuts[i], right, cuts);
            answer = min(answer, current);
        }

        return dp[l][r] = answer;
    }
    int minCost(int n, vector<int> &cuts)
    {
        dp = vector<vector<int>>(cuts.size() + 4, vector<int>(cuts.size() + 2, -1));
        sort(cuts.begin(), cuts.end());
        return recursion(0, cuts.size() - 1, 0, n, cuts);
    }
};