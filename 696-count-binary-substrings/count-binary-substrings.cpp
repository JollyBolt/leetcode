class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> v;
        int count = 1;
        int n = s.size();
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                v.push_back(count);
                count=1;
            }
            else count++;
        }
        v.push_back(count);
        int ans = 0;
        for(int i=0;i<v.size()-1;i++){
            ans += min(v[i],v[i+1]);
        }
        return ans;
    }
};