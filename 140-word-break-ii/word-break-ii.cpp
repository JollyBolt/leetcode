class Solution {
public:
    void solve(int idx,string s,string temp,vector<string>& ans,unordered_set<string> dict,vector<int>
    & dp){
        if(idx==s.size()) {
            temp.pop_back();
            ans.push_back(temp);
            return ;
        }

        // if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.size();i++){
            if(dict.count(s.substr(idx,i-idx+1))){
                // temp += s.substr(idx,i-idx+1);
                // temp += " ";
                solve(i+1,s,temp+s.substr(idx,i-idx+1)+" ",ans,dict,dp);
                // temp.pop_back();
                // temp -=s.substr(idx,i-idx+1);
                dp[idx] = true;

            }          
        }
        // return dp[idx] = false;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<string> ans;
        string temp;
        vector<int> dp(s.size(),-1);
        solve(0,s,temp,ans,dict,dp);
        return ans;
    }
};