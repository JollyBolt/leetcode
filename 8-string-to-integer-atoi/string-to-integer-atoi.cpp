class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int ans=0;
        bool neg=false;
        int i=0;
        while(i<n){
            if(s[i]==' ') i++;
            else break;
        }
        if(s[i]=='-' or s[i]=='+'){
            if(s[i]=='-') neg=true;
            i++;
        }

        int limit = INT_MAX / 10;
        while(i<n and isdigit(s[i])){
            int digit = s[i]-'0';
            if(ans>limit || ans==limit && digit>7){
                return neg?INT_MIN:INT_MAX;
            }
            ans = ans*10 + digit;
            i++;
        }
        if(neg) ans*=-1;
        return ans;
    }
};