class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int cnt = 0, i = num1.length() - 1, j = num2.length() - 1;
        while (i >= 0 || j >= 0 || cnt) {
            if (i >= 0) cnt += num1[i--] - '0';
            if (j >= 0) cnt += num2[j--] - '0';
            ans.push_back((cnt % 10) + '0');
            cnt /= 10; 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};