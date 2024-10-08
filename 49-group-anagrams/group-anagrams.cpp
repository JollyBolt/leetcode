class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;
        int n = strs.size();
        for(int i=0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]); 
        }
        for(auto x:m){
            int len = x.second.size();
            vector<string> v;
            for(int i=0;i<len;i++){
                v.push_back(x.second[i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};