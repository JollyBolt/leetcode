class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int i=0,n=intervals.size();
        while(i<n){
            int start=intervals[i][0];
            int final=intervals[i][1];
            vector<int> temp;
            temp.push_back(start);
            int j=i;
            while(j<n-1 and final>=intervals[j+1][0]){
                final=max(final,intervals[j+1][1]);
                j++;
            }
            i=j+1;
            temp.push_back(final);
            ans.push_back(temp);
        }
        return ans;
    }
};