class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        // vector<vector<int>> matrix(rows,vector<int>(cols,0));
        vector<vector<int>> ans;
        int i=rStart,j=cStart;
        int count=1;
        ans.push_back({i,j});
        // matrix[rStart][cStart] = 1;
        int steps=0;
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        int direction = 0;
        while(count<rows*cols){
            if(direction==0 or direction==2) steps++;
            for(int x=0;x<steps;x++){
                i+=dir[direction][0];
                j+=dir[direction][1];
                if((i<rows and i>=0) and (j>=0 and j<cols)) {
                    ans.push_back({i,j});
                    count++;
                }
            }
            if(direction==3) direction=0;
            else direction++;

        }
        return ans;
    }
};