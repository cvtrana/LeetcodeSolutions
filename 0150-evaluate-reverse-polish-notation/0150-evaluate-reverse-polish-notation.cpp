class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n =  tokens.size();
        stack<int> s;
        
        for(int i=0;i<n;i++){
            if(tokens[i]=="+" || tokens[i]=="*" || tokens[i]=="/" || tokens[i]=="-"){
                if(tokens[i]=="+"){
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    int val = a+b;
                    s.push(val);
                    
                }
                else if(tokens[i]=="*"){
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    int val = a*b;
                    s.push(val);
                    
                }
                else if(tokens[i]=="-"){
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    int val = b-a;
                    s.push(val);
                    
                }
                else if(tokens[i]=="/"){
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    int val = b/a;
                    s.push(val);
                    
                }
            }
            else{
                string x = tokens[i];
                int b = stoi(x);
                s.push(b);
            }
        }
        return s.top();
        
    }
};