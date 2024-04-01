class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        vector<int> indices;
        for(int i=0;i<n;i++){
            if(words[i]==target) indices.push_back(i);
        }
        if(indices.size()==0) return -1;

        int left = startIndex,right=startIndex,count = 0;
        while(1){
            if(words[left] == target||words[right]==target) break;
            if(left==0) left=n-1;
            else left--;
            if(right==n-1) right = 0;
            else right++;
            count++;
        }

        return count;
    }
};