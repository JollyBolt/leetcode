class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int left = 0,right = 0;
        int n = nums.size();
        while(right<n and nums[right]<0) right++;
        left = right-1;
        for(int i=0;i<n;i++) nums[i] *= nums[i];
        while(left>=0 or right<n){
            if(left<0) ans.push_back(nums[right++]); 
            else if(right==n) ans.push_back(nums[left--]);
            else if(nums[left]<nums[right]) ans.push_back(nums[left--]);
            else ans.push_back(nums[right++]);  
        }
        return ans;
    }
};