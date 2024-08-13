class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int ans=1;
        string pal=s.substr(0,1);
        for(int i=0;i<n;i++){
            int left,right;
            //odd
            left=i-1,right=i+1;
            while(left>=0 and right<n and s[left]==s[right]){
                if(right-left+1>ans){
                    ans=max(ans,right-left+1);
                    pal=s.substr(left,right-left+1);
                }
                right++;
                left--;
            }
            //even
            if(s[i+1]==s[i]){
                if(ans<2){
                    ans=2;
                    pal=s.substr(i,2);
                }
                left=i-1,right=i+2;
            while(left>=0 and right<n and s[left]==s[right]){
                if(right-left+1>ans){
                    ans=max(ans,right-left+1);
                    pal=s.substr(left,right-left+1);
                }
                right++;
                left--;
            }
            }
        }
        return pal;
    }
};