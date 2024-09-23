class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum<abs(target) or (sum+target)%2!=0) return 0;
        int ntarget = (sum+target)/2;

        //Initialization
        vector<vector<int>> dp(n,vector<int>(ntarget+1,0));
        for(int i=0;i<=ntarget;i++){
            if(i==0 and i==nums[0]) dp[0][i] = 2;
            else if(i==0 or i==nums[0]) dp[0][i] = 1;
            else dp[0][i]=0;
        }

        //tabulation
        for(int i=1;i<n;i++){
            for(int j=0;j<=ntarget;j++){
                int take = 0;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                dp[i][j] = take + dp[i-1][j];
            }
        }
        return dp[n-1][ntarget];
    }
};