class Solution {
public:
    int mySqrt(int x) {
        if( x < 2 ) {
            return x;
        }
        int lo = 1;
        int hi = x / 2;
        long long mid = 0;
        long long sq = 0;
        while( lo <= hi ) {
            mid = (hi + lo) / 2;
            sq = mid * mid;
            if( sq == x ) {
                return mid;
            }
            if( sq < x ) {
                lo = mid + 1;
            } else if( sq > x ) {
                hi = mid - 1;
            }
        }
        return ( sq >= x ) ? ( mid - 1 ) : mid;
    }
};
