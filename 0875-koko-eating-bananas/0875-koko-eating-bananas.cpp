class Solution {
public:
    bool is_possible(int mid,vector<int> &piles,int h){
        long long  hours = 0;
        for(int i=0;i<piles.size();i++){
            if(piles[i] <= mid){
                hours+=1;
            }
            else{
                hours += piles[i]/mid;
                long long rem = piles[i]%mid;
                if(rem!=0){
                    hours++;
                }
            }
        }
        if(hours<=h){
            return true;
        }
        else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // easy binary search problem
        int low =1;
        int high = 1e9;
        int mini = 1e9;
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if(is_possible(mid,piles,h)){
                mini = min(mini,mid);
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return mini;
        
    }
};