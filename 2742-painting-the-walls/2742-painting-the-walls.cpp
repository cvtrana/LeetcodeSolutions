class Solution {
public:
    
    int find_min_cost(vector<int>& cost, vector<int>& time, int t, vector<vector<int>>& dp,int i)
    {
        if(t>=cost.size())
        {
            return dp[i][t]=0;
        }
        else if(i==0 && t<cost.size())
        {
            return dp[i][t]=INT_MAX-1000000;
        }

        int len=cost.size();

        if(dp[i][t]!=-1)
        {
            return dp[i][t];
        }

        int cost1=cost[i-1]+find_min_cost(cost, time, t+time[i-1]+1, dp, i-1);
        int cost2=find_min_cost(cost, time, t, dp, i-1);

        return dp[i][t]=min(cost1, cost2);
        
    }

    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        int i, sub_ans, min_ans=INT_MAX, n=cost.size(), total_time=0;
        vector<int> painted(cost.size(), 0);
        for(i=0;i<time.size();i++)
        {
            total_time+=time[i];
        }

        vector<vector<int>> dp(n+4, vector<int> (total_time+4, -1));

        return find_min_cost(cost, time, 0, dp, n);

    }
};