class Solution {
public:
    int tribonacci(int n) {
        int t[ 3 ];
        t[ 0 ] = 0;
        t[ 1 ] = 1;
        t[ 2 ] = 1;
        if( n < 2 ) {
            return t[ n ];
        }
        for( int i = 2; i < n; ++i ) {
            const int temp = t[ 2 ];
            t[ 2 ] = t[ 2 ] + t[ 1 ] + t[ 0 ];
            t[ 0 ] = t[ 1 ];
            t[ 1 ] = temp;
        }
        return t[ 2 ];
    }
};
