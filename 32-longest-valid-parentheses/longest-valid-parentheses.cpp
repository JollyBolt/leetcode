class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<pair<char,int>> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty() or s[i]=='('){
                st.push({s[i],i});
            }
            else {
                if(st.top().first=='('){
                    st.pop();
                    if(st.empty()) ans=max(ans,i+1);                   
                    else ans=max(ans,i-st.top().second);
                }
                else st.push({s[i],i});    
            }
        }
        return ans;
    }
};