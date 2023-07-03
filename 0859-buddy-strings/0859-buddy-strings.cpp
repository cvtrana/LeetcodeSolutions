class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n =  s.length();
        int m = goal.length();
        map<char,int> m1;
        map<char,int> m2;
        
        for(int i=0;i<n;i++){
            m1[s[i]]++;
            m2[goal[i]]++;
            
        }
        if(s==goal){
            for(auto x:m1){
                if(x.second>=2){
                    return true;
                }
            }
            return false;
            
        }
        if(s[0]==goal[0] && m1.size()==1 && m2.size()==1){
            return true;
        }
        if(n!=m){
            return false;
        }
        
        
        bool flag = false;
        vector<int> change;
        
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]){
                change.push_back(i);
            }
            
        }
        if(change.size()>2 || change.size()<2){
            return false;
        }
        else{
            swap(s[change[0]],s[change[1]]);
            
            if(s==goal){
                return true;
            }
            return false;
            
        }
        
    }
};