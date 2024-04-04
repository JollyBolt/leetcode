class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int,int> m;
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        
        sort(v.begin(),v.end());
        vector<int> ans;
        for(int i = 0;i<n-1;i++){
            int tempTarget = target-v[i].first;
            int start = i+1,end=n-1;
            while(start<=end){
                int mid = start + (end-start)/2;
                if(v[mid].first == tempTarget){
                    ans.push_back(v[i].second);
                    ans.push_back(v[mid].second);
                    return ans;
                } 
                else if(v[mid].first > tempTarget) end=mid-1;
                else start = mid+1;
            }
        }
        return ans;
    }
};