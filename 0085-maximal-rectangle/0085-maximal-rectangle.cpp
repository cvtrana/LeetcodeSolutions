class Solution {
public:
    int largestRectangleArea(vector <int> & histo) {
          stack <int> st;
          int maxA = 0;
          int n = histo.size();
          for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
              int height = histo[st.top()];
              st.pop();
              int width;
              if (st.empty())
                width = i;
              else
                width = i - st.top() - 1;
              maxA = max(maxA, width * height);
            }
            st.push(i);
          }
          return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        
        vector<int> height(n);
        int m = matrix.size();
        int maxi = -1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                
                else{
                    height[j] = 0;
                }
            }
            //cout << maxi << endl;
            int area = largestRectangleArea(height); // area of histogram using stack approach
            maxi = max(maxi,area);
            
        }
        return maxi;
        
    }
};