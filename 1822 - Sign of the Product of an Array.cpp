class Solution {
public:
    int signFunc( const int x ) {
        if( x > 0 ) {
            return 1;
        } else if ( x < 0 ) {
            return -1;
        }
        return 0;
    }
    int arraySign(vector<int>& nums) {
        int product = 1;
        for( int i = 0; i < nums.size(); ++i ) {
            product *= signFunc( nums[i] );
        }
        return product;
    }
};
