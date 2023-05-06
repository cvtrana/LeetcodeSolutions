class Solution {
public:
int bs(int l,int r,int t,vector<int>&v)
{
    if(r>=l)
    {
    int mid=l+(r-l)/2;
    if(v[mid]==t)
    return mid;
    else if(v[mid]<t)
    return bs(mid+1,r,t,v);
    
    return bs(l,mid-1,t,v);
    }

    return -1;
}
    int searchInsert(vector<int>& v, int t)
    {
        int n=v.size();
        int ans=bs(0,n-1,t,v);
        if(ans!=-1)
        return ans;
         int c=0;
        for(auto i:v)
        {
            if(t>i)
            c++;
        }
        return c;

       
        
    }
};