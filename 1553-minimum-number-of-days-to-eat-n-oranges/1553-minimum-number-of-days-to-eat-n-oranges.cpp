class Solution {
public:
    int minDays(int n) {
        unordered_map<int,bool> vis;
        queue<pair<int,int> > q;
        q.push({n,0});
        int ans = 0;
        while(!q.empty())
        {
            ans++;
            pair<int,int> x = q.front();
            q.pop();
            int num = x.first;
            int days = x.second;
            if (num == 0)
                return days;
            if (vis.find(num-1) == vis.end())
                q.push({num-1,days+1}), vis[num-1] = true;
            if (num % 2 == 0)
                q.push({num/2,days+1}), vis[num/2] = true;
            if (num % 3 == 0)
                q.push({num-(2*(num/3)),days+1}), vis[num-(2*(num/3))] = true;
        }
        return ans;
    }
};