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

    int solve(vector<string>& board,int c,int n){
        if(c==n){
            return 1;
        } 
        int ans=0;
        for(int i=0;i<n;i++){
            if(isValid(board,i,c,n)){
                board[i][c]='Q';
                ans+=solve(board,c+1,n);
                board[i][c]='.';
            }
                     
        }
        return ans;
    }

    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        return solve(board,0,n);
    }
};