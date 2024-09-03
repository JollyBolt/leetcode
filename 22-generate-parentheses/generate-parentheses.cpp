class Solution {
public:
    void util(int index,int sum,int n,string s,vector<string>& ans){
        if(index==(2*n)) {
            if(sum==0)
            ans.push_back(s);
            return;
        }
        if(sum<n) {
            s+='(';
            util(index+1,sum+1,n,s,ans);
            s.pop_back();
        }
        if(sum>0) {
            s+=')';
            util(index+1,sum-1,n,s,ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        util(0,0,n,s,ans);
        return ans;
    }
};