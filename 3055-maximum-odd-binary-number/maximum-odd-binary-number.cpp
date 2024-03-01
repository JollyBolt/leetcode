class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        string ans;
        int countOne = 0;
        for(auto x:s){
            if(x=='1') countOne++;
        }
        int zeros = n-countOne;
        for(int i=0;i<countOne-1;i++) ans+='1';
        for(int i=0;i<zeros;i++) ans+='0';
        ans+='1';
        return ans;
    }
};