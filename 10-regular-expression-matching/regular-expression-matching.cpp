class Solution {
public:
    bool solve(int i, int j, string s, string p, vector<vector<int>>& dp){
        if(j==p.size()){
            return i==s.size();
        }

        if(dp[i][j]!=-1) return dp[i][j];

        bool first_char_matched = false;
        if(i<s.size() and p[j]=='.' or s[i]==p[j]) {
            first_char_matched = true;
        }

        if(p[j+1]=='*'){
            bool notTake = solve(i,j+2,s,p,dp);
            bool take = first_char_matched && solve(i+1,j,s,p,dp);
            return dp[i][j] = take or notTake;
        }
        return dp[i][j] = first_char_matched && solve(i+1,j+1,s,p,dp);
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(0,0,s,p,dp);
    }
};