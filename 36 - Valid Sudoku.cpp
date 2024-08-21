class Solution {
    static const int bitMask = ~0x3; // Ascii values are assigned a bit, starts at '.' in ascii for speed
    static const int numRows = 9;
    static const int numCols = 9;
    static const int subBoxSize = 3;

    inline static int getNum( const char pieceCode ) {
        const int result = pieceCode - '.'; // Ascii: . / 0 1 2 ... 9
        return result;
    }

    inline static bool isValid( const uint32_t cellCheck, const int cellValue ) {
        return !( cellCheck & ( 1 << cellValue ) & bitMask );
    }

    inline static void markCell( uint32_t& cellCheck, const int cellValue ) {
        cellCheck |= ( 1 << cellValue );
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        uint32_t rowCheck[ numRows ];
        uint32_t colCheck[ numCols ];
        uint32_t gridCheck[ subBoxSize * subBoxSize ];

        for( int j = 0; j < numRows; ++j ) {
            for( int i = 0; i < numCols; ++i ) {
                const int num = getNum( board[ j ][ i ] );

                const int gridId = ( i / subBoxSize ) + subBoxSize * ( j / subBoxSize );

                // Rows will finish before grids, grids before columns
                const bool valid = isValid( rowCheck[ j ], num ) && isValid( gridCheck[ gridId ], num ) && isValid( colCheck[ i ], num );
                if( valid == false ) {
                    return false;
                }
                markCell( rowCheck[ j ], num );
                markCell( colCheck[ i ], num );
                markCell( gridCheck[ gridId ], num );
            }
        }
        return true;
    }
};
