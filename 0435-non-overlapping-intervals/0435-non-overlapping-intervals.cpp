class Solution {
public:
    int get_intervals(vector<vector<int>>& intervals,int i, vector<int>&dp){
        if(i>=intervals.size()) return 0;
        if(dp[i] != -1) return dp[i];

        vector<int>temp = {intervals[i][1],INT_MIN};
        int it = upper_bound(intervals.begin(),intervals.end(),temp) - intervals.begin();
        int include = 1 + get_intervals(intervals,it,dp);;

        int exclude = get_intervals(intervals,i+1,dp);
           
        return dp[i] = max(include,exclude);
    } 
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int>dp(n+1,-1);
        return n - get_intervals(intervals,0,dp) ;
    }
};