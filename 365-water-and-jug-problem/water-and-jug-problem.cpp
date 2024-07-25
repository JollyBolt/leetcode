class Solution {
public:
    int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target) return false;
        if(target%gcd(x,y)==0) return true;
    return false;
    }
};