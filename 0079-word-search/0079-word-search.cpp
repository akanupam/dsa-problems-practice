class Solution {
public:
    bool found(int i, int j, vector<vector<char>> &board, string word, int index){
        if(index == word.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[index]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool ans = found(i,j+1, board, word, index+1)||
                   found(i-1, j, board, word, index+1)||
                   found(i+1, j, board, word, index+1)||
                   found(i, j-1, board, word, index+1);
        
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(found(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};