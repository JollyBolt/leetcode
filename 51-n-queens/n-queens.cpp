class Solution {
public:
    bool isValid(vector<string> board,int r,int c,int n){
        if(c==0) return true;
        int row=r;
        int col=c;
        while(c>=0)
        if(board[r][c--]=='Q')
        return false;

        r=row,
        c=col;
        while(c>=0 and r>=0)
        if(board[r--][c--]=='Q')
        return false;

        r=row,
        c=col;
        while(c>=0 and r<n)
        if(board[r++][c--]=='Q')
        return false;

        return true;

    }
    void solve(vector<vector<string>>& ans,vector<string>& board,int c,int n){
        if(c==n){
            ans.push_back(board);
            return;
        } 
        for(int i=0;i<n;i++){
            if(isValid(board,i,c,n)){
                board[i][c]='Q';
                solve(ans,board,c+1,n);
                board[i][c]='.';
            }          
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        // string s(n,'.');
        // for(int i=0;i<n;i++){
        //     board.push_back(s);
        // }
        solve(ans,board,0,n);
        return ans;
    }
};