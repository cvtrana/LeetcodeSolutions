class Solution {
public:
    bool possible(int mid,vector<vector<int>> &matrix,int target){
        int m = matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[mid][i]==target){
                return true;
            }
            
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0;
        int high = n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            cout << mid << endl;
            
            if(possible(mid,matrix,target)){
                return true;
            }
            else if(target > matrix[mid][m-1]){
                low = mid+1;
                
            }
            else if(target < matrix[mid][m-1]){
                
                high = mid-1;
            }
        }
        return false;
        
    }
};