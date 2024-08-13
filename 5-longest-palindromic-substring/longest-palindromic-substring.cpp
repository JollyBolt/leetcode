class Solution {
public:
    //Expand from center function
    string expand(int left,int right,string s){
        int n = s.size();
        while(left>=0 and right<n and s[left]==s[right]){
            right++;
            left--;
        }
        return s.substr(left+1,right-1-(left+1)+1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans="";
        for(int i=0;i<n;i++){
            int left,right;
            //odd
            string odd = expand(i,i,s);
            if(odd.size()>ans.size()) ans=odd;
            //even
            string even = expand(i,i+1,s);
            if(even.size()>ans.size()) ans=even;
        }
        return ans;
    }
};