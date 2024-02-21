class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int low=0,high=n;
        while(low<high){
            int mid = (low+high)>>1;
            int left,right;
            if(mid==0) left=nums[n-1];
            else left=nums[mid-1];
            right=nums[(mid+1)%n];
            if(nums[mid]<right and nums[mid]<left) return nums[mid];
            if(nums[mid]>nums[n-1]) low=mid+1;
            else high=mid;
        }
        return 0;
    }
};