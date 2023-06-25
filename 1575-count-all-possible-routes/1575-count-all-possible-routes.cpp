class Solution {
public:
    int mod = 1e9 + 7;
    int func(vector<int> &locations , int start , int finish , int fuel , vector<vector<int>>
    &dp){
        if(fuel < 0) return 0;
        if (dp[start][fuel] != -1) return dp[start][fuel];
        int ans = 0;
        
        if (start == finish) ans++;
        
        for (int i=0;i<locations.size();i++){
            if (i == start || abs(locations[i] - locations[start]) > fuel) continue;
            ans += func(locations , i , finish , fuel - abs(locations[i] - locations[start]) ,dp) % mod;

            ans %= mod;
        }
        return dp[start][fuel] = ans % mod;
}
int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int sz = locations.size();
    vector<vector<int>> dp(sz , vector<int>(fuel + 1 , -1));

    return func(locations , start , finish , fuel , dp);
    }
};