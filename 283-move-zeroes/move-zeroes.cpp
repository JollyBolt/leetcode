class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        while(i<n and j<n){
            if(nums[j]!=0){
                swap(nums[i++],nums[j++]);
            }
            else j++;
        }
    }
};