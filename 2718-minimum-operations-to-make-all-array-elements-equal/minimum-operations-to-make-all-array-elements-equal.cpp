class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<long long> prefix(n);
        vector<long long> ans;
        prefix[0] = nums[0];
        for(int i=1;i<n;i++) prefix[i]=nums[i]+prefix[i-1];
        for(int i=0;i<queries.size();i++){
            long long ub = upper_bound(nums.begin(),nums.end(),queries[i]) -nums.begin();
            long long inc = 0,dec = 0;
            if(ub>0) inc = queries[i]*(ub) - prefix[ub-1];
            if(ub < n){
                dec = prefix[n-1] - queries[i]*(n - ub);
                if(ub>0) dec-=prefix[ub-1];
            } 
            ans.push_back(inc + dec);
        } 
        return ans;
    }
};