class Solution {
public:
    // int util(int idx,int amount,vector<int>& coins,vector<vector<int>>& dp){
    //     if(amount == 0) return 0;
    //     if(idx == 0){
    //         if(amount%coins[idx] == 0) return amount/coins[idx];
    //         return 1e5;
    //     } 
    //     if(dp[idx][amount]!=-1) return dp[idx][amount];

    //     int take = 1e5;
    //     if(amount>=coins[idx])
    //     take = 1 + util(idx,amount-coins[idx],coins,dp);
    //     int notTake = util(idx-1,amount,coins,dp);

    //     return dp[idx][amount] = min(take,notTake);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));

        for(int i=0;i<=amount;i++) dp[0][i] = amount%coins[0] == 0? amount/coins[0]:1e5;
        for(int i=0;i<=n;i++) dp[i][0] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                int take = 1e5;
                if(j>=coins[i-1])
                take = 1 + dp[i][j-coins[i-1]]; 
                int notTake = dp[i-1][j]; 
                dp[i][j] = min(take,notTake);
            }
        }
        int ans = dp[n][amount];
        if(ans>=1e5) return -1;
        return ans;
    }
};