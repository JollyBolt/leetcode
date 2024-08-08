class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        int mini=nums[n-1];
        for(int i=n-1;i>=2;i--){
            mini=min(mini,nums[i]);
            if(mini<nums[i-2]) return false; 
        }
        return true;
    }
};