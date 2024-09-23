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
        if(sum<abs(target) or (sum+target)%2!=0) return 0;
        // return util(n-1,(sum+target)/2,nums);
        int ntarget = (sum+target)/2;
        vector<vector<int>> dp(n,vector<int>(ntarget+1,0));
        for(int i=0;i<=ntarget;i++){
            if(i==0 and i==nums[0]) dp[0][i] = 2;
            else if(i==0 or i==nums[0]) dp[0][i] = 1;
            else dp[0][i]=0;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==0) dp[i][0] =  2;
            else dp[i][0] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=ntarget;j++){
                int take = 0;
                if(nums[i]<=j) take = dp[i-1][j-nums[i]];
                dp[i][j] = take + dp[i-1][j];
                // if(nums[i]==0) dp[i][j] += 2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=ntarget;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return dp[n-1][ntarget];

    }
};