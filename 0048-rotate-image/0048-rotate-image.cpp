class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp(matrix.size());
        reverse(matrix.begin(), matrix.end());
        int j = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (auto& arr : matrix) {
                tmp[j].push_back(arr[i]);
            }
            j++;
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[i][j] = tmp[i][j];
            }
        }
    }
};