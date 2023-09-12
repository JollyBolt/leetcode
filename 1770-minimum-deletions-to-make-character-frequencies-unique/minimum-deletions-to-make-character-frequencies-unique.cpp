class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int> v(26,0);
        for(int i=0;i<n;i++){
            v[s[i] -'a']++;
        }
        sort(v.begin(),v.end());
        int index=0;
        while(v[index]==0) index++;
        unordered_map<int,int>m;
        for(int i=index;i<26;i++){
            m[v[i]]++;
        }
        int ans=0;
        int x=v[25]-1;
        cout<<x;
        for(int i=25;i>index;i--){
            if(v[i]==v[i-1]){
                if(x==0){
                    ans+=v[i];
                }
                else{
                    while(x>=v[i] or m.find(x) != m.end()){
                        x--;
                    }
                    ans+=v[i]-x;
                    if(x) x--;
                }
            }
        }
        return ans;
    }
};