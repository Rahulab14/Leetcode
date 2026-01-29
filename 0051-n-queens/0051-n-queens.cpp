class Solution {
public:

    bool isfound(int n,vector<string>&board,int row,int col){
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q'){
                return false;
            }

        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i=>0&&j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;

    }

    void backtracking(int n,vector<vector<string>>&result,vector<string>&board,int row){
        if(n==row){
            result.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if(isfound(n,board,row,col)){
                board[row][col]='Q';
                backtracking(n,result,board,row+1);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>board(n,string(n,'.'));
        backtracking(n,result,board,0);
        return result;
        
    }
};