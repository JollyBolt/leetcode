class Solution {
public:
    void util(int index,vector<int>& temp,unordered_map<int,int>& m,int n,vector<vector<int>>& ans){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        for(auto x:m){
            if(x.second>0){
                temp[index] = x.first;
                m[x.first]--;
                util(index+1,temp,m,n,ans);
                m[x.first]++;
            }
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) m[nums[i]]++;
        vector<int> temp(n);
        util(0,temp,m,n,ans);
        return ans;
    }
};