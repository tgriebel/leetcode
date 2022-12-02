class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int direction = 0;
        for( int i = 1; i < nums.size(); ++i ) {
            int delta = ( nums[i] - nums[i - 1] );
            if( delta != 0 ) {
                if( direction == 0 ) {
                    direction = ( delta < 0 ) ? -1 : 1;
                }
                if( ( delta * direction ) < 0 ) {
                    return false;
                }
            }
        }
        return true;
    }
};
