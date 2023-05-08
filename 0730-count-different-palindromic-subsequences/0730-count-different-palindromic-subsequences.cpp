class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n = s.length();
        unordered_map<char, int> m;
        int prev[n];
        int next[n];
        int modulo = 1000000007;
        
        for(int i = 0; i < n; ++i) {
            if(m.find(s[i]) != m.end()) {
                prev[i] = m[s[i]];
            }
            else {
                prev[i] = -1;
            }
            m[s[i]] = i;
        }
        
        m.clear();
        for(int i = n - 1; i >= 0; --i) {
            if(m.find(s[i]) != m.end()) {
                next[i] = m[s[i]];
            }
            else {
                next[i] = -1;
            }
            m[s[i]] = i;
        }
        
        vector<vector<long long int>> dp(n, vector<long long int>(n));
        
        for(int g = 0; g < n; ++g) {
            
            for(int i = 0, j = g; j < n; ++i, ++j) {
                if(g == 0) {
                    dp[i][j] = 1;
                }
                else if(g == 1) {
                    dp[i][j] = 2;
                }
                else {
                    if(s[i] != s[j]) {
                        dp[i][j] = (dp[i][j - 1]%modulo + dp[i + 1][j]%modulo - dp[i + 1][j - 1]%modulo)%modulo;
                    }
                    
                    else {
                        int n = next[i];
                        int p = prev[j];
                        
                        if(n == p) {
                            dp[i][j] = (2*dp[i + 1][j - 1] + 1)%modulo;
                        }
                        else if(n < p) {
                            dp[i][j] =((2*dp[i + 1][j - 1])%modulo - (dp[n + 1][p - 1])%modulo)%modulo;
                        }
                        else {
                            dp[i][j] = (2*dp[i + 1][j - 1] + 2)%modulo;
                        }
                    }
                }
                if(dp[i][j] < 0)
                    dp[i][j] += modulo;
            }
        }
        
        return dp[0][n - 1];
    }
};