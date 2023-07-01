class Solution {
public:
    int ans = INT_MAX;
    void dfs(int ind,vector<int> &cookies,int k , vector<int> bags){
        if(ind >= cookies.size()){
            int maxi =0;
            for(int i=0;i<bags.size();i++){
                maxi = max(maxi,bags[i]);
            }
            ans = min(ans,maxi);
            return;
        }
        
        // sare bag mein daal kr dekho
        
        for(int i=0;i<k;i++){
            bags[i] += cookies[ind];
            dfs(ind+1,cookies,k , bags);
            bags[i]-=cookies[ind]; // backtrack 
            if(bags[i]==0){
                break;
            }
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
         // simple backtracking approach 
        vector<int> bags(k);
        dfs(0,cookies,k,bags);
        
        return ans;
        
        
        
        
        
        
    }
};