class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> hash(n+1,0);
        for(int i=0;i<=n;i++){
            if(ranges[i]==0) continue;
            int start = max(0,i-ranges[i]);
            int end = min(n,i+ranges[i]);
            hash[start]=max(hash[start],end);

        }
        if(hash[0]==0) return -1;
        int maxEnd = hash[0];
        int currEnd = hash[0];
        int taps = 1;
        for(int i=1;i<=n;i++){
            if(i>currEnd){
                if(i>maxEnd) return -1;
                else {
                    currEnd = maxEnd;
                    taps++;
                }
            }
            if(hash[i]>maxEnd) maxEnd=hash[i];
        }
        return taps;
    }
};