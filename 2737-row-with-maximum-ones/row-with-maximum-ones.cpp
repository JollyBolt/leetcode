class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int ans=0;
        int currMax=0;
        for(int i = 0;i<rows;i++){
            int ones = 0;
            for(int j=0;j<cols;j++){
                ones+=mat[i][j];
            }
            if(ones>currMax) {
                ans=i;
                currMax=ones;
            }
        }
        return {ans,currMax};
    }
};