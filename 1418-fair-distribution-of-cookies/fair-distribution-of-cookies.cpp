class Solution {
public:
    int util(int index,int maxi,vector<int>& children,vector<int>& cookies){
        if(index==cookies.size()){
            int highest=0;
            for(int i=0;i<children.size();i++) 
            highest=max(highest,children[i]); 
            return highest;
        }
        for(int i=0;i<children.size();i++){
            children[i]+=cookies[index];
            maxi=min(maxi,util(index+1,maxi,children,cookies));
            children[i]-=cookies[index];
        }
        return maxi; 
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int maxi=INT_MAX;
        int n=cookies.size();
        if(k==n){
            maxi=0;
            for(int i=0;i<n;i++) maxi=max(maxi,cookies[i]);
            return maxi;
        }
        vector<int> children(k,0);
        return util(0,maxi,children,cookies);
    }
};