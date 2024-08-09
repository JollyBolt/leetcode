class Solution {
public:
    bool isValid(vector<int>& bloomDay, int m, int k,int check){
        int curr=0,count=0;
        int n = bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=check){
                curr++;
            }
            else curr=0;
            if(curr==k){
                curr=0;
                count++;
            }
        }
        if(count>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m>n/k) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high  = *max_element(bloomDay.begin(),bloomDay.end());
        if(m*k==n/k) return high;
        while(low<high){
            int mid = low + (high-low)/2;
            if(isValid(bloomDay,m,k,mid)) high=mid;
            else low=mid+1;
        }
        return high;
    }
};