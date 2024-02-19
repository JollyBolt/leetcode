class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> hash(n+1,0);
        for(int i = 0; i<n; i++){
            hash[nums[i]]++;
            if(hash[nums[i]]==2) ans.push_back(nums[i]);
        }
        return ans;
    }
};