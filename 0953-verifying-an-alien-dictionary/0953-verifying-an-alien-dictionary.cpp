class Solution {

public:
    bool isAlienSorted(vector<string>& word, string order) {
 
       vector<int> converter(26, 0);
        for(int k = 0 ; k<26 ; k++)
        converter[order[k]-'a'] = k;

        int i = 1;

        while(i<word.size())
        {
           if(converter[word[i][0]-'a']<converter[word[i-1][0]-'a'])
           return false;
           else if(converter[word[i][0]-'a'] == converter[word[i-1][0]-'a'])
           {
               int j = 1;

               while(j<word[i].size() && j<word[i-1].size())
               {
                   if(converter[word[i][j]-'a'] == converter[word[i-1][j]-'a'])
                   j++;
                   else
                   break;
               }

               if(j == word[i].size() && j != word[i-1].size())
               return false;
               else if(j<word[i].size() && j<word[i-1].size()) 
               {
                   if(converter[word[i][j]-'a'] < converter[word[i-1][j]-'a'])
                   return false;
               }
           }

           i++;
        }

        return true;
    }
};