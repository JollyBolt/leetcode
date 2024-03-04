class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int score=0;
        int ans=0;
        int i=0,j=n-1;
        while(i<=j){
            if(score==0 and power<tokens[i]) break;
            else{
                if(power >= tokens[i]){
                    score++;
                    power-=tokens[i];
                    i++;
                }else{
                    score--;
                    power+=tokens[j];
                    j--;
                }
            }
            ans = max(ans,score);
        }
        return ans;
    }
};