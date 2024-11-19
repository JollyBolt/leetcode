class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=nums[i];
            for(int y=0;y<i-1;y++){
                // if(i==n-1 and y==0) continue;
                dp[i]=max(dp[i],nums[i]+dp[y]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};