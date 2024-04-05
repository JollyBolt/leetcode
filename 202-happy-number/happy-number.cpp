class Solution {
public:
    int sqSum(int n){
        int ans = 0;
        while(n){
            int r = n%10;
            ans += r*r;
            n/=10;
        }
        return ans;
    }

    bool isHappy(int n) {
        unordered_map<int,int> m;
        while(m.count(n)==0){
            m[n]=1;
            n = sqSum(n);
            cout<<n<<endl;
            if(n==1) return true;
        }
        return false;
    }
};