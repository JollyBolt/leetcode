class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int col0  = matrix[0][0];

        //Marking for zeroes
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    if(j == 0) col0=0;
                    else {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }

        //Inner matrix
        for(int i=rows-1;i>=1;i--){
            for(int j = cols-1;j>=1;j--){
                if(matrix[0][j]==0 or matrix[i][0]==0) matrix[i][j]=0;
            }
        }

        //1st row
        for(int j=cols-1;j>=1;j--){
            if(matrix[0][0]==0) matrix[0][j]=0;
        }
        //1st col
        for(int i=rows-1;i>=0;i--){
            if(col0==0) matrix[i][0]=0;
        }

    }
};