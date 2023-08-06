# define i64 long long
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD = 1'000'000'007;
        vector<vector<i64>> dp(n + 1, vector<i64> (goal + 1));
        dp[0][0] = 0;
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][i] = (dp[i - 1][i - 1] * i) % MOD;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= goal; j++) {
                (dp[i][j] = dp[i][j - 1] * max(0LL, (i64)i - k) + dp[i - 1][j - 1] * i) %= MOD;

            }
        }
        return dp[n][goal];
    }
};