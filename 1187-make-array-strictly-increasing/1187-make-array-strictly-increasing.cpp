class Solution {
public:
    // two states - replace it or dont replace + upperbound
    int help(map<pair<int,int>,int>&dp,int prev,int i,vector<int>& arr1, vector<int>& arr2) {
        if(i==arr1.size())return 0;
        if(dp.find({i,prev})!=dp.end())return dp[{i,prev}];

        int ans=INT_MAX/2;
        int id=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        if(arr1[i]>prev)ans=min(ans,help(dp,arr1[i],i+1,arr1,arr2));
        if(id<arr2.size())ans=min(ans,help(dp,arr2[id],i+1,arr1,arr2)+1);
        
        return dp[{i,prev}]=ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        map<pair<int,int>,int> dp;
        int ans= help(dp,INT_MIN,0,arr1,arr2);
        return ans>=INT_MAX/2?-1:ans;
    }
};