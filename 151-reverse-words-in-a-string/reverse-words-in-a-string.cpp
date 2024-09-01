class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        int n = s.size();
        while(s[j]==' ') j++;
        swap(s[i],s[j]);
        j++;
        while(j<n){
            if(s[j]!=' ' or s[j]==' ' and s[i]!=' '){
                swap(s[i+1],s[j]);
                i++;
            }
            j++;
        }
        j=n-1;
        while(s[j--]==' ') s.pop_back();
        reverse(s.begin(),s.end());
        i=0,j=0;
        while(j<n){
            if(j==n-1 or s[j+1]==' '){
                reverse(s.begin()+i,j==n-1?s.end():s.begin()+j+1);
                i=j+2;
                j++;
            }
            j++;
        }
        return s;
    }
};