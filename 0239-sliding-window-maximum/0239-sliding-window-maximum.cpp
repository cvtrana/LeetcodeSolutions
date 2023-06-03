class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // can we use a priority queue here??
        int n  =  nums.size();
        vector<int> nge(n);
        vector<int> ans;
        stack<int> s;
        s.push(n-1);
        nge[n-1] = n;
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && nums[i] >= nums[s.top()]){
                s.pop();
            }
            if(s.empty()){
                nge[i] = n;
            }
            else{
                nge[i] = s.top();
            }
            s.push(i);
            
            
            
        }
        int j =0;
        
        for(int i=0;i<=n-k;i++){
            cout << i << endl;
            if(j < i){
                j=i;
            }
           
            while(nge[j] < i+k){
                j = nge[j];
            }
            ans.push_back(nums[j]);
            
            
        }
        return ans;
        
    }
};