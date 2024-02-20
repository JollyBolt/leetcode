class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        int num3 = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<num3) return true;
            
            while(!s.empty() and nums[i]>s.top()){
                num3=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        
        return false;   
    }
};