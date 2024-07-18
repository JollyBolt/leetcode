class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        //Checking the target can exist in the matrix
        if(matrix[0][0]> target or matrix[rows-1][cols-1]<target) return false;
        //Checking if the target is 1st or last element to avaid unnecessary computation
        if(matrix[0][0] == target or matrix[rows-1][cols-1] == target) return true;

        //Binary search to find the row where the element can exist
        int start = 0, end = rows;
        while(start<end){
            int mid = start + (end - start)/2;
            if(matrix[mid][0]>target) end=mid;
            else start=mid+1;
        }
        int row = end - 1;

        //Binary search to find if the element exists in the row
        start = 0, end = cols - 1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target) end=mid-1;
            else start=mid+1;
        }
        return false;
        
    }
};