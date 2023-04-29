class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        // if at any point remainder repeats , then it is divisble by k
        int cnt =0;
        map<int,int> m;
        int s =0;
        int rem = 0;
        m[rem]++;
        for(int i=0;i<nums.size();i++){
            s += nums[i];
            rem = s%k;
            if(rem < 0){
                rem += k;
            }
            if(m.find(rem)!= m.end()){
                cnt += m[rem];
                m[rem]++;
            }
            else{
                m[rem] =1; // else insert it in the map
            }
        }
        return cnt;
        
    }
};