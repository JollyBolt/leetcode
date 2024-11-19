class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = n-2;
        while(ind>=0){
            if(nums[ind]<nums[ind+1]) break;
            else ind--;
        }
        if(ind>=0){
            int sind=ind+1;
            int x = nums[sind];
            for(int i=sind;i<n;i++){
                if(nums[i]>nums[ind] and nums[i]<=x){
                    x=nums[i];
                    sind=i;
                }
            }
            swap(nums[ind],nums[sind]);
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};