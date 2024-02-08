class Solution {
public:
    void util(vector<int>& temp,unordered_map<int,int> m,vector<int>& nums,vector<vector<int>>& ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                temp.push_back(nums[i]);
                m[nums[i]]=1;
                util(temp,m,nums,ans);
                temp.pop_back();
                m.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int,int> m;
        vector<int> temp;
        util(temp,m,nums,ans);
        return ans;
    }
};