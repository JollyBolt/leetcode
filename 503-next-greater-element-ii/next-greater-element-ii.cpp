class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
    int n=v.size();
    vector<int> nge(n,0);
    
    stack<int>s;
    int maxi=v[0],index=0;
    for(int i=1;i<n;i++){
        if(v[i]>=maxi){
            index=i;
            maxi=v[i];
        }
    }
    int k=n;
    int i=index;
    while(k--){
        while(!s.empty() and s.top()<=v[i]) s.pop();
        if(s.empty()) nge[i]=-1;
        else nge[i]=s.top();
        s.push(v[i]);
        i--;
        if(i==-1) i=n-1;   
    }
    
    return nge;
}
};