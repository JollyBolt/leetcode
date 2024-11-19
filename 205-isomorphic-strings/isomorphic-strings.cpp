class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return 0;
        int n = s.size();
        unordered_map<char,char> to;
        unordered_map<char,char> from;
        for(int i=0;i<n;i++){
            if(to.count(s[i])==0 and from.count(t[i])==0) {
                to[s[i]] = t[i];
                from[t[i]]= s[i];
            }
            else if(to[s[i]]!=t[i]) return 0;
        }
        return 1;
    }
};