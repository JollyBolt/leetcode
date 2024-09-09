class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";
        for(int i=0;i<=n;i++) ans+='0'+i+1;
        int i = 0;
        while(i<n){
            if(pattern[i]=='D'){
                int j=i+1;
                while(j<n and pattern[j]=='D') j++;
                reverse(ans.begin()+i,ans.begin()+j+1);
                i=j;
            }
            i++;
        }

        return ans;
    }
};