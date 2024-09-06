class Solution {
public:
    int util(int ind, int target, vector<int>& nums){
        if(ind==0){
            if(nums[0]==0 and target==0) return 2;
            if(target-nums[0]==0 or target+nums[0]==0) return 1;
            return 0;
        } 
        return util(ind-1,target-nums[ind],nums)+util(ind-1,target+nums[ind],nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return util(n-1,target,nums);
    }
};