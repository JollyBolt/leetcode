class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<pair<char,int>> st;
        st.push({')',-1});
        for(int i=0;i<s.size();i++){
            if(s[i]==')' and st.top().first=='('){
                st.pop();
                ans=max(ans,i-st.top().second);
            }
            else st.push({s[i],i});
        }
        return ans;
    }
};