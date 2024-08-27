class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = s+s;
        int n=str.size();
        for(int i=1;i<n-s.size();i++){
            if(str.substr(i,s.size())==s) return true;
        }
        return false;
    }
};