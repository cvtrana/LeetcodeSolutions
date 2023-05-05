class Solution {
public:
    int dp[2001][2005 ];
    int rec(int ind,int k,vector<int> &stones){
        // base case
        if(ind == stones.size())return false;
        if(ind == stones.size()-1){
            return true;
        }
        
        
        // check
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        
        bool x = false,y=false,z=false;
        
        for(int i = ind+1;i<stones.size();i++){
             if(stones[i]-stones[ind]==k)
            {
                x|=rec(i,k,stones);
            }
            if(stones[i]-stones[ind]==k+1)
            {
                y|=rec(i,k+1,stones);
            }
            if(stones[i]-stones[ind]==k-1)
            {
                z|=rec(i,k-1,stones);
            }
        }
        return dp[ind][k] = (x || y || z);
        
        
        
        
        
    }
    bool canCross(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        
        // changing parameters  -  index and k
        
        // dp[0][0] -> ans;
        
        int n = stones.size();
        
        int ans = rec(0,0,stones);
        return ans;
        
    }
};