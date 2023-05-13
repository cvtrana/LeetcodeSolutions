class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1}); // word and pathlength
        s.erase(beginWord);

        while(!q.empty()){
            string  f = q.front().first;
            int ans = q.front().second;
            q.pop();
            if(f==endWord){
                return ans;
            }
            for(int i=0;i<f.size();i++){
                char in = f[i];
                for(char c ='a';c<='z';c++){
                    f[i] = c;
                    if(s.find(f)!=s.end()){
                        q.push({f,ans+1});
                        s.erase(f);
                    }
                }
                f[i] = in; // original string

            }
        }
        return 0;

        
    }
};