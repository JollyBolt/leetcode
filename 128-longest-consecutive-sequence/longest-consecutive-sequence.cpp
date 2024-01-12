class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        // if(n==0) return 0; 
        for(int i=0;i<n;i++) s.insert(nums[i]);
        int maxi=0;
        int i=0;
        while(i<n){
            if(s.find(nums[i]-1)!=s.end()) i++;
            // else if(s.find(nums[i]+1)==s.end()) i++;
            else {
                int curr=1;
                int j=nums[i]+1;
                while(s.find(j)!=s.end()){
                    curr++;
                    j++;
                }
                maxi=max(maxi,curr);
                i++;
            }
        }
        return maxi;
    }
};