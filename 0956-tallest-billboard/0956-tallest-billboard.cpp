class Solution {
    
public:
    int ans;
    const static int offset = 5000;
    int dp[21][2*offset+1];
    
    int rec(int ind,int diff,vector<int>&rods){
        // base case
        if(ind==rods.size()){
            if(diff==0){
                return 0;
            }
            return INT_MIN;
        }
        
        if(dp[ind][offset+diff]!=-1){
            return dp[ind][offset+diff];
        }
        
        int op1 = rec(ind+1,diff,rods) ; // not take
        int op2 = rods[ind] + rec(ind+1,diff + rods[ind],rods);
        int op3 = rods[ind] + rec(ind+1,diff - rods[ind],rods);
        return dp[ind][offset+diff] = max({op1,op2,op3});
    }
    int tallestBillboard(vector<int>& rods) {
        // for every sum can we find to disjoint subsets ...
        
        memset(dp,-1,sizeof(dp));
        
        ans = rec(0,0,rods); // index,diff
        int len = ans/2;
        
        return len;
        
    
        
        
    }
};