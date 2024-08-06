class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};