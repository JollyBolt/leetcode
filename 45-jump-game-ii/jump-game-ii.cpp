class Solution {
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        if(n==1) return 0;
        vector<int> hash(n,0);
        for(int i=0;i<n;i++) hash[i]=min(n-1,i+nums[i]);
        int jumps=1;
        int currEnd = hash[0];
        int maxEnd = hash[0];
        for(int i=1;i<n;i++){
            if(i>currEnd){
                currEnd = maxEnd;
                jumps++;
            }
            maxEnd = max(maxEnd,hash[i]);
        }
        return jumps;
    }
};