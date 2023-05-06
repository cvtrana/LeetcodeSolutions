class Solution {
private:
    int getNeighbors(vector<vector<int>>& board, int i, int j){
        int result = 0;
        result += getLive(board, i-1, j-1); // top-left
        result += getLive(board, i-1, j); // top
        result += getLive(board, i-1, j+1); // top-right
        result += getLive(board, i, j-1); // left
        // result += getLive(board, i, j); // doesn't count itself
        result += getLive(board, i, j+1); // right
        result += getLive(board, i+1, j-1); // bottom-left
        result += getLive(board, i+1, j); // bottom
        result += getLive(board, i+1, j+1); // bottom-right
        return result;
    }
    int getLive(vector<vector<int>>& board, int i, int j){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return 0;
        else
            return board[i][j];
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> init = board;
        int row = board.size();
        int col = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                int n =  getNeighbors(init,i,j);
                int cell = init[i][j];
                if(cell == 1){ // when cell lives
                    if(n < 2) cell = 0;
                    else if(n == 2 || n == 3)   cell = 1;
                    else if(n > 3) cell = 0;
                } else { // when cell died
                    if(n == 3) cell =1;
                }
                if(init[i][j] != cell) // if changed cells stadius
                    board[i][j] = cell;
            }    
        }
        
    }
};