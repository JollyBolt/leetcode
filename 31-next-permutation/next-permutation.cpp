class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = n-2;
        while(ind>=0){
            if(nums[ind]<nums[ind+1]) break;
            else ind--;
        }
        if(ind>-1){
            for(int i=n-1;i>ind;i--){
                if(nums[i]>nums[ind]){
                    swap(nums[ind],nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};