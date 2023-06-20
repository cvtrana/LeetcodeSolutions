class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,cmp> pq;
        int n =  nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
            
        }
        int ans = -1;
        while(pq.size()){
            ans= pq.top();
            cout << ans <<" ";
            break;
            pq.pop();
        }
        cout << endl;
        return ans;
        
    }
 private:
    struct cmp{
        bool  operator()(int a,int b){
            return a > b;
        }
        
        
    };
};