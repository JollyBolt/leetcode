class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return 0;
        int target = sum/2;
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int i=0;i<=target;i++){
            if(i==0) dp[0][i] = 1;
            else dp[0][i]=0;
        }
        for(int i=1;i<n;i++) dp[i][0] = 1; 

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                int take = 0;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                dp[i][j] = max(take,dp[i-1][j]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=target;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[n-1][target]>0?1:0;
    }
};