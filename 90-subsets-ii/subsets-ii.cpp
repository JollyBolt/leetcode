class Solution {
public:
    void subsetsWithDupHelper(int index,vector<int> temp,vector<int>& nums,vector<vector<int>>& ans){
        if(index == nums.size()) return;
        
        for(int i=index;i<nums.size();i++){
            if(i>index and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            ans.push_back(temp);
            subsetsWithDupHelper(i+1,temp,nums,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        sort(nums.begin(),nums.end());
        subsetsWithDupHelper(0,temp,nums,ans);
        return ans;
    }
};