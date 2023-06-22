class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int  n = hand.size();
        
        if(n%groupSize!=0){
            // cout << "hii";
            return false;
            
        }
        else{
            
            multiset<int> s;
            for(int i=0;i<hand.size();i++){
                s.insert(hand[i]);
            }
            
            auto it = s.begin();
            //cout <<*it << endl;
            while(!s.empty()){
                int element = *it;
                s.erase(it);
                int temp = groupSize;
                temp--;
                while(temp--){
                    auto x = s.lower_bound(element+1);
                    cout <<*x << endl;
                    if(x==s.end() || *x!= element+1){
                        return false;
                    }
                    s.erase(x);
                    element++;
                }
                
                it = s.begin();
                
            }
            return true;
            
        }
        
    }
};