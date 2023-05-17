class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        // two pointer
        int cnt =0;
        int n =  people.size();
        
        sort(people.begin(),people.end());
        
        
        int i =0;
        int j = n-1;
        
        while(i<=j){
            int temp = people[i] + people[j];
            
            // case 1:
            if(temp <=limit){
                cnt++;
                i++;
                j--;
                
            }
            else if(temp > limit){
                j--;
                cnt++;
                
            }
              
            
            
            
        }
        return cnt;
        
    }
};