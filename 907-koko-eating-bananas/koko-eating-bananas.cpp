class Solution {
public:
    bool isValid(int check,vector<int>& piles, int h){
        int hours=0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            if(piles[i]<=check) hours++;
            else {
                hours += ceil(double(piles[i])/(check));

            }
            if(hours>h) return false;
        // cout<<check<<":"<<hours<<" ";
        }
        if(hours>h) return false;
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = INT_MAX;
        int maxBanana = piles[0];

        for(int i=0;i<n;i++){
            maxBanana = max(maxBanana,piles[i]);
        }

        int low = 1,high = maxBanana;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(isValid(mid,piles,h)){
                ans = min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};