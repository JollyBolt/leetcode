class Solution {
public:
    int util(int ind, int target, vector<int>& nums){
        if(ind==0){
            if(target==0 and target==nums[0]) return 2;
            if(target==0 or target==nums[0]) return 1;
            return 0;
        } 
        return util(ind-1,target-nums[ind],nums)+util(ind-1,target,nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum+target)%2!=0) return 0;
        // vector<vector<int>> dp(n+1,vector<int>(-1));
        return util(n-1,(sum+target)/2,nums);
        // vector<vector<int>> dp(n+1,vector<int>(target+1));
    }
};