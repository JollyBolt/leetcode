class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        while(i<n and j<n){
            if(nums[i]==0 and nums[j]!=0){
                swap(nums[i++],nums[j++]);
            }
            else {
                if(nums[i]!=0) {
                    i++;
                    j++;
                }
                if(j<n and nums[j]==0) j++;
            }
        }
    }
};