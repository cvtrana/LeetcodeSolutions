class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int> mp;

        for(int i = 1; i <= n; i++){
            int num = i;
            int sum = 0;

            while(num){
                int rem = num%10;
                sum += rem;
                num /= 10;
            }

            mp[sum]++;
        }   

        int max_ = 0;

        for(auto it:mp){
            max_ = max(max_, it.second);
        }

        int ans = 0;
        for(auto it:mp){
            if(max_ == it.second){
                ans++;
            }
        }

        return ans;
    }
};