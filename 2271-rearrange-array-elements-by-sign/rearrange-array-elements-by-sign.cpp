class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg,pos;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) neg.push_back(nums[i]);
            else pos.push_back(nums[i]);
        }
        int i=0,j=0,z=0;
        while(z<n){
            if(z%2==0){
                nums[z]=pos[i++];
            }else{
                nums[z]=neg[j++];
            }
            z++;
        }
        return nums;
    }
};
