class Solution {
public:
    int romanToInt(string s) {
        int num=0,n=s.size();
        unordered_map<char,int> m{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0;i<n;i++){
            if(i<n-1 and m[s[i]]<m[s[i+1]]){
                num+=m[s[i+1]]-m[s[i]];
                i++;
            }
            else num+=m[s[i]];
        }
        return num;
    }
};