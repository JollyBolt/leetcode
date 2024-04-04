class Solution {
public:
    int minFlips(string target) {
        char curr = '0';
        int count = 0;
        int n = target.size();
        for(int i=0;i<n;i++){
            if(target[i]!=curr){
                count++;
                if(curr=='0') curr='1';
                else curr = '0';
            }

        }
        return count;
    }
};