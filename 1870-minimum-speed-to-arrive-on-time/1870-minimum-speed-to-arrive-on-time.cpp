class Solution {
    bool possible(vector<int>& dist, double hours,int speed)
    {
        double currHours=0;
        for(auto d:dist)
        {
            currHours+=(d*1.0/speed);
            if(currHours>hours)return false;
            currHours=ceil(currHours);
        }
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int lo=1,hi=1e9;
        int ans=-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(possible(dist,hour,mid))
            {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};