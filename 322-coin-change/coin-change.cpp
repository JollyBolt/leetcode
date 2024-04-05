class Solution {
public:
    int util(int idx,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(idx == 0){
            if(amount%coins[idx] == 0) return amount/coins[idx];
            return 1e5;
        } 
        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int take = 1e5;
        if(amount>=coins[idx])
        take = 1 + util(idx,amount-coins[idx],coins,dp);
        int notTake = util(idx-1,amount,coins,dp);

        return dp[idx][amount] = min(take,notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = util(n-1,amount,coins,dp);
        if(ans>=1e5) return -1;
        return ans;
    }
};