class Solution {
public:
    bool safe(vector<string> board,int row,int col, int n){
        int duprow = row;
        int dupcol = col;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col = dupcol;
        row = duprow;
        while(col>=0 && row>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row--;
        }
        col = dupcol;
        row = duprow;
        while(col>=0 && row<n){
            if(board[row][col]=='Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void backtrack(vector<vector<string>> &res, vector<string> &board, int n, int index){
        if(index==n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(safe(board, i, index, n)){
                board[i][index] = 'Q';
                backtrack(res, board, n, index+1);
                board[i][index] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board.push_back(s);
        }
        backtrack(res, board, n, 0);
        return res;
    }
};