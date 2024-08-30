class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0,right = n-1, lmax=0, rmax=0, ans=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]<=lmax) ans+=lmax-height[left];
                else lmax= height[left];
                left++;
            }
            else{
                if(height[right]<=rmax) ans+=rmax-height[right];
                else rmax= height[right];
                right--;
            }
        }
        return ans;

    }
};