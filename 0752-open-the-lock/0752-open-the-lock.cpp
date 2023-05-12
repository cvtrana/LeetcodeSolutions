class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        unordered_set<string> ends(deadends.begin(), deadends.end());
        int size, turns = 0, a, b;
        string curr, tmp;
        
        q.push("0000");
        while (!q.empty()) {
            size = q.size();
            
            while (size) {
                size--;
                curr = q.front(); q.pop();
                if (curr == target) return turns;
                if (ends.find(curr) != ends.end()) continue;
                ends.insert(curr);
                
                for (int i = 0; i < 4; i++) { // chaar baar rol kr skte hai
                    tmp = curr;
                    a = tmp[i] - '0' + 1; // rolling fwd
                    b = tmp[i] - '0' - 1; // rolling bck
                    
                    if (b < 0) b += 10;
                    a %= 10; b %= 10;
                    
                    tmp[i] = a + '0';
                    q.push(tmp);
                    
                    tmp[i] = b + '0';
                    q.push(tmp);
                }
            }
            turns++;
        }
        return -1;
    }
};