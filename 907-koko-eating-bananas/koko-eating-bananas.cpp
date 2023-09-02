class Solution {
public:
    bool isValid(int mid,int h,vector<int>& piles){
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=ceil(double(piles[i])/mid);
        }
        cout<<mid<<":"<<hours<<endl;
        if(hours<=h) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = piles[0];
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int low=1,high=maxi;
        int ans=maxi;
        while(low<high){
            int mid=low + (high-low)/2;
            if(isValid(mid,h,piles)){
                ans=min(ans,mid);
                high=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};