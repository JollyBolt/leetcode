class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int> v(26,0);
        for(int i=0;i<n;i++){
            v[s[i] -'a']++;
        }
        sort(v.begin(),v.end());

        int ans=0;

        for(int i=24;i>=0;i--){
            if(v[i]==0) break;
            if(v[i]>=v[i+1]){
                ans+=v[i]-max(0,v[i+1]-1);
                v[i]=max(0,v[i+1]-1);
            }
        }
        return ans;
    }
};