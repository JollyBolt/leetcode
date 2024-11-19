class Solution {
public:
    int util(vector<int>& nums,int start,int end){
        int n = nums.size();
        vector<int> dp(n,0);
        dp[start]=nums[start];
        for(int i=start+1;i<end;i++){
            dp[i]=nums[i];
            for(int y=start;y<i-1;y++){
                dp[i]=max(dp[i],nums[i]+dp[y]);
            }
        }
        // int ans
        return *max_element(dp.begin()+start,dp.begin()+end);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(util(nums,0,n-1),util(nums,1,n));
    }
};