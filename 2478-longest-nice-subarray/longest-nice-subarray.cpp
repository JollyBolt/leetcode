class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int i=0,j=1;
        int curr=nums[0];
        int ans=1;
        while(j<n){
            while(i<j and (curr & nums[j])!=0){
                curr ^= nums[i];
                i++;
            }
            ans=max(ans,j-i+1);
            curr |= nums[j];
            j++;
        }
        return ans;
    }
};