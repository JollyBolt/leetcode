class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;
        vector<int> prefix;
        prefix.push_back(arr[0]);
        for(int i=1;i<n;i++){
            prefix.push_back(arr[i]^prefix[i-1]);
        }
        int nq = queries.size();
        for(int i=0;i<nq;i++){
            int left = queries[i][0], right = queries[i][1];
            int xorr = prefix[right];
            if(left>0) xorr = xorr^prefix[left-1];
            ans.push_back(xorr);
        }
        return ans;

    }
};