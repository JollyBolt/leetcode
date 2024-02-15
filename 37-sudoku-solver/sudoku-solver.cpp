class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        for(int i = 0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(c,i,j,board)){
                            board[i][j] = c;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
        bool isValid(char c,int row,int col,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==c) return false;
        
            if(board[i][col]==c) return false;

            int nRow = 3 * (row/3) + i/3;
            int nCol = 3 * (col/3) + i%3;

            if(board[nRow][nCol]==c) return false;
        }

        return true;
    }
};