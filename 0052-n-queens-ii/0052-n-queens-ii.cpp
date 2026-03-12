class Solution {
public:
    bool isSafe(int n, vector<string>& board, int row, int col){
        
        // check column
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q') return false;
        }

        // check upper left diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        // check upper right diagonal
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void backtrack(int n, vector<string>& board, int row, int &count){
        if(row == n){
            count++;
            return;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(n, board, row, col)){
                board[row][col] = 'Q';
                backtrack(n, board, row + 1, count);
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int count = 0;
        backtrack(n, board, 0, count);
        return count;
    }
};