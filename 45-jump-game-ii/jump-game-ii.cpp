class Solution {
public:
    int nextJump(int index,vector<int>& nums,vector<int>& dp){
        if(nums[index]==0) return INT_MAX;
        if(nums[index]>=nums.size()-index-1) return 1;

        if(dp[index]!=-1){
            return dp[index];
        }

        int jumps=INT_MAX;
        for(int i=1;i<=nums[index];i++){
            jumps=min(jumps,nextJump(index+i,nums,dp)==INT_MAX?INT_MAX:1+nextJump(index+i,nums,dp));
        }
        return dp[index]=jumps;
    }
    int jump(vector<int>& nums){
        int n = nums.size();
        if(n==1) return 0;
        vector<int> dp(n,-1);
        return nextJump(0,nums,dp);
    }
};
/*

*/