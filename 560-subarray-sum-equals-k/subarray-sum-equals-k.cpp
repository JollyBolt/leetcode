class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size(), sum = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m.count(sum-k)>0) ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
        
    }
};