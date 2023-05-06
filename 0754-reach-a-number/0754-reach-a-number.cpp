#define ll long long
class Solution {
public:
    
    int reachNumber(int target) {
        
        target=abs(target);
        
       int num=(-1 + sqrt((long long) (1 + (long long)8*target)))/2;
        
        if((num*(num+1))/2 == target)
        {
            return num;
        }
        
        int curr_num=(num*(num+1))/2;
        
        num++;
        
        curr_num+=(num);
        
        while((abs(curr_num - target))%2!=0)
        {
            num++;
            curr_num+=num;
        }
        return num;
    }
};