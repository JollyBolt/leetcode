class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i=0,j=n-1;
        while(i<j){
            if(i==j) break;
            if(s[i]==s[j]){
                while(i<j and s[i]==s[i+1]) i++;
                while(i<j and s[j]==s[j-1]) j--;
                i++;
                j--;
            }
            else break;
        }
        if(j<i) return 0;
        return j-i+1;

        
    }
};