class Solution {
public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = (n+m)*mean;
        int currSum = 0;
        for(int i=0;i<m;i++) currSum+=rolls[i];
        int reqSum = sum - currSum;
        if(reqSum<n or reqSum>(n*6)) return {};
        int div = reqSum/n, rem = reqSum%n;
        vector<int> ans(n,div);
        for(int i=0;i<rem;i++) ans[i]++;
        return ans;


    }
};