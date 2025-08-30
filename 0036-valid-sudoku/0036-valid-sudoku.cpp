class Solution {
public:
   bool areRulesMet(vector<vector<char>>& board, int row, int col, char digit) {
        for (int i = 0; i < 9; i++) {
            if (i != col && board[row][i] == digit) return false;  // skip same cell
            if (i != row && board[i][col] == digit) return false;  // skip same cell
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if ((i != row || j != col) && board[i][j] == digit) {
                    return false;  // skip same cell
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
          int n = 9;  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(board[i][j]!='.'){
                    if(areRulesMet(board,i,j,board[i][j])==false)return false;
                }
            }
            }
        return true;  
    }
};