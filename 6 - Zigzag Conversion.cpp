class Solution {
    enum class Direction : unsigned int {
        DOWN,
        DIAG,
        RIGHT
    };

public:
    string convert(string s, int numRows) {
        const int numCols = s.size();
        const int stringLength = s.size();
        char grid[ numRows ][ numCols ];

        // Initialize
        for( int j = 0; j < numRows; ++j ) {
            for( int i = 0; i < stringLength; ++i ) {
                grid[ j ][ i ] = ' ';
            }
        }

        // Zig-zag conversion
        int x = 0;
        int y = 0;

        Direction d = Direction::DOWN;

        for( int i = 0; i < stringLength; ++i ) {
            // Put character
            grid[ y ][ x ] = s[ i ];

            // Change direction
            if( ( d == Direction::DOWN ) && ( y == ( numRows - 1 ) ) ) {
                d = ( numRows > 1 ) ? Direction::DIAG : Direction::RIGHT;
            } else if ( ( d == Direction::DIAG ) && ( y == 0 ) ) {
                d = Direction::DOWN;
            }
        
            // Advance
            if( d == Direction::DOWN ) {
                ++y;
            } else if( d == Direction::RIGHT ) {
                ++x;
            } else if( d == Direction::DIAG ) {
                --y;
                ++x;
            }
        }

        // Create new string
        string result;
        for( int j = 0; j < numRows; ++j ) {
            for( int i = 0; i < numCols; ++i ) {
                if( grid[ j ][ i ] != ' ' ) {
                    result += grid[ j ][ i ];
                }
            }
        }
        return result;
    }
};
