class Solution {
public:
    
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        int x = pow(2,n-2);
        if(k<=x) return kthGrammar(n-1,k);
        else return 1 - kthGrammar(n-1,k-x);
    }
};
/*
1 = 0
2 = 01
3 = 01 10
4 = 0110 1001
5 = 0110 1001 1001 0110
6 = 0110 1001 1001 0110 1001 0110 0110 1001
*/