class Solution {
public:
    void util(int index, vector<int> temp,vector<int>& nums,vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i]==11){
                temp[i] = nums[index];
                util(index+1,temp,nums,ans);
                temp[i]=11;
            }  
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> temp(n,11);
        util(0,temp,nums,ans);
        return ans;
    }
};