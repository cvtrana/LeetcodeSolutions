class Solution {
public:
    vector<string > ans;
    void rec(int ind,string s,vector<string> chk)
    {
        if(ind == chk.size())
        {
            ans.push_back(s);
            return;
        }
        for(int i=0;i<chk[ind].size();i++)
        {
            s+=chk[ind][i];
            rec(ind+1,s,chk);
            s.pop_back();

        }
    }
    vector<string> letterCombinations(string digits) 
    {
        map<char,string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        vector<string> chk;
        for(int i=0;i<digits.size();i++)
        {
            chk.push_back(m[digits[i] ]);
        }
        char s = digits[0];
        char j = s;
        string start = m[j];
        for(int i=0;i<start.size();i++)
        {
            string s = "";
            string h = "";
            h+=start[i];
            rec(1,h,chk);
        }
        return ans;
        


        
    }
};