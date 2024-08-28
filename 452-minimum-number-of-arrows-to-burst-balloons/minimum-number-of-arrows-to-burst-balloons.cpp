class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        int count = 1;
        int curr_end = points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]<=curr_end) curr_end=min(curr_end,points[i][1]);
            else {
                count++;
                curr_end=points[i][1];
            }
        }
        return count;
    }
};