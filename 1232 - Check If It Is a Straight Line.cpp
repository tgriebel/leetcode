class Solution {
public:
    inline float getSlope( int x0, int y0, int x1, int y1 ) {
        const float rise = ( y1 - y0 );
        const float run = ( x1 - x0 );
        if( run != 0.0f ) {
            return ( rise / run );
        } else {
            return INT_MAX;
        }
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];
        float m0 = getSlope( x0, y0, x1, y1 );
        float m1 = 1.0f;

        x0 = x1;
        y0 = y1;

        for( int i = 2; i < coordinates.size(); ++i ) {
            x1 = coordinates[i][0];
            y1 = coordinates[i][1];

            m1 = getSlope( x0, y0, x1, y1 );
            if( ( m1 - m0 ) != 0.0f ) {
                return false;
            }
            x0 = x1;
            y0 = y1;
            m0 = m1;
        }
        return true;
    }
};
