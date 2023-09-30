class Solution {
public:
    string removeDuplicateLetters(string s) {
        int a[26]={0};
        bool b[26]={false};
        int n=s.size();
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;    
        }
        string ans="";
        stack<char> st;
        for(int i=0;i<n;i++){
            if(b[s[i]-'a']==true) {
                a[s[i]-'a']--; 
                continue;
            }
            while(!st.empty() and s[i]<=st.top() and a[st.top()-'a']>1){
                a[st.top()-'a']--;
                b[st.top()-'a']=false;
                st.pop();
            } 
            st.push(s[i]);
            b[s[i]-'a']=true;
        }

        while(!st.empty()){
            ans+=st.top();
            // if(a[st.top()-'a']==1) ans+=st.top();
            // else a[st.top()-'a']--;
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};