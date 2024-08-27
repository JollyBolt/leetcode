class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i=2;i<=n;i++){
            int len = s.size();
            string ns = "";
            int c=1;
            char ch=s[0];
            for(int j=1;j<len;j++){
                if(s[j]==s[j-1]) c++;
                else{
                    ns+=char('0'+c);
                    ns+=ch;
                    ch=s[j];
                    c=1;
                }
            }
            ns+=char('0'+c);
            ns+=ch;
            s=ns;
        }
        return s;
    }
};