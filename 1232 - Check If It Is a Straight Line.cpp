class Solution {
public:
    inline float getSlope( int dx, int dy ) {
        return ( dx != 0 ) ? ( dy / static_cast<float>( dx ) ) : 1000000.0f;
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx = ( coordinates[1][0] - coordinates[0][0] );
        int dy = ( coordinates[1][1] - coordinates[0][1] );
        float m0 = getSlope( dx, dy );

        for( int i = 2; i < coordinates.size(); ++i ) {
            dx = ( coordinates[i][0] - coordinates[i - 1][0] );
            dy = ( coordinates[i][1] - coordinates[i - 1][1] );
            const float m1 = getSlope( dx, dy );

            if( ( m1 - m0 ) != 0.0f ) {
                return false;
            }
            m0 = m1;
        }
        return true;
    }
};
