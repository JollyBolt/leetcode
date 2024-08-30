class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(numRows==1) return s;
        vector<string> v(numRows,"");
        string dir = "down";
        int row=0;
        for(int i=0;i<n;i++){
            v[row]+=s[i];
            if(dir=="down"){
                if(row==numRows-1){
                    dir="up";
                    row--;
                }
                else row++;
            }
            else{
                if(row==0){
                    dir="down";
                    row++;
                }
                else row--;
            }
        }
        string ans;
        for(int i=0;i<numRows;i++) ans+=v[i];
        return ans;
    }
};