class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if( (((~n)+1)&n)==n ) return true;
        
        return false;
    }
};