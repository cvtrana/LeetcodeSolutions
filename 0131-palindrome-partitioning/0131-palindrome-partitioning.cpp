class Solution {
private:
    //function to check the string between start and end index is a palindrome or not
    bool isPalindrome(string& s, int start, int end)
    {
        while(start<=end) 
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> res;

        solve(0, s, res, ans);

        return ans;
    }

    void solve(int ind, string& s, vector<string>& res, vector<vector<string>>& ans)
    {
        if(ind==s.length())
        {
            ans.push_back(res);
            return ;
        }

        for(int i=ind; i<s.length(); i++)
        {
        //generating each substring and checking for palindrome
            if(isPalindrome(s, ind, i))
            {
                res.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, res, ans);

            //Popping back because backtrack
                res.pop_back();
            }
        }

        return ;
    }
};