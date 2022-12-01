class Solution {
public:
    int climbStairs(int n) {
        if( n <= 2 ) {
            return n;
        }
        int steps[ 3 ] = { 0, 1, 2 }; // How many paths to get to the step
        for( int i = 2; i < n; ++i ) {
            steps[ 0 ] = steps[ 1 ] + steps[ 2 ];
            steps[ 1 ] = steps[ 2 ];
            steps[ 2 ] = steps[ 0 ];
        }
        return steps[ 2 ];
    }
};
