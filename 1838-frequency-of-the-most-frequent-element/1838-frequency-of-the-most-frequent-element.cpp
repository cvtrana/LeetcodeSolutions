class Solution {
public:
    bool is_possible(int mid, vector<int> &nums,int k,vector<long long > &pref){
        long long  window =  mid;
        //cout << window << endl;
        // checking each window of size mid
        
        long long i =0;
        long long  j = 0;
     
        
        while(j<nums.size()){
            if(j-i+1==window){
                
                if(i==0){
                    
                    long long  sum =  pref[j];
                    long long  required_sum = window *(nums[j]);
                    long long  to_get = required_sum - sum;
                    
                    if(to_get <= k){
                        return true;
                    }
                    
                }
                else{
                    
                    long long  sum =  pref[j] - pref[i-1];
                    long long required_sum = window*(nums[j]);
                    
                    // will take the maximum element
                    
                    long long to_get = required_sum - sum;
                   
                    if(to_get <= k){
                        return true;
                    }   
                }
                
                i++;
                j++;
                
            }
            else{
                j++; 
                
            }
               
        }
        return false;
        
        
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<long long > pref(n);
        sort(nums.begin(),nums.end());
         // binary search on the window
        //vector<int> pref(n);
        pref[0]  =  nums[0];
        
        for(int i=1;i<n;i++){
            pref[i] =  pref[i-1] +  nums[i];
        }
        
        // storing the prefix sum
        
        int low = 0;
        int high = 1e6;
        int ans = 1;
        while(low <= high){
            int mid =  (low + high)/2;
            //cout << mid << endl;
            if(is_possible(mid,nums,k,pref)){
                // search for a greater freq
                ans =  max(ans,mid);
                cout << mid << endl;
                low=  mid + 1;
            }
            else{
                // move to the backward region
               high =  mid - 1;
            }
        }
        return ans ; // containing the highest freq
        
        
        
    }
};