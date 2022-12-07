class Solution {
public:
    bool isPerfectSquare(int num) {
        if( num == 1 ) {
            return true;
        }
        int lo = 0;
        int hi = num / 2;
        while( lo <= hi ) {
            long long mid = ( hi + lo ) / 2;
            long long midSquared = ( mid * mid );
            if( midSquared == num ) {
                return true;
            } else if ( midSquared > num ) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;
    }
};
