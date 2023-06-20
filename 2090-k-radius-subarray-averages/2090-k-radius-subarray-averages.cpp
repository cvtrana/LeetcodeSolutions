class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        // suffix and prefix arrays
        int n = nums.size();
        vector<int> ans(n);
        long long pref[n];
        long long suff[n];
        if(k==0){
            return nums;
        }
        if(k > n){
            for(int i=0;i<n;i++){
                ans[i] = -1;
            }
            return ans;
        }
        if(n==1){
            ans[0] = nums[0]/(2*k+1);
            return ans;
        }
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];
        
        for(int i=1;i<n;i++){
            pref[i] = nums[i] + pref[i-1];
        }
        for(int i = n-2;i>=0;i--){
            suff[i] = suff[i+1] + nums[i];
        }
        
        for(int i=0;i<n;i++){
            
            if(i-k >=0 && i+k <n){
                
                // do something 
                long long  term1 ,term2;
                if(i-k ==0){
                    term1 = pref[i];
                }
                else{
                    // do something
                    term1 = pref[i] - pref[i-k-1];
                    cout << term1 << " " << endl;
                }
                if(i+k+1 < n){
                    //cout << suff[i+1] <<" " << suff[i+k+1] << endl;
                    term2 = suff[i+1] - suff[i+k+1];
    
                }
                else{
                    
                    term2 = suff[i+1];
                        
                    
                    
                    
                }
                
                long long val  = floor((double)(term1 + term2)/(2*k+1));
                ans[i] = val;
                
            }
            else{
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};