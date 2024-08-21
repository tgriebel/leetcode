class Solution {
    static const int bitMask = ~0x3; // Each ascii value is assigned a bit, starts at '.' in ascii for speed. Non-numbers are masked from checks
    static const int numRows = 9;
    static const int numCols = 9;
    static const int subBoxSize = 3;

    inline static int getBitNum( const char pieceCode ) {
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
        // For each row, column, and subGrid, check if a number was seen before. It's invalid if it was seen
        // Use bitfields, for every possible check, to track if a number was seen 

        uint32_t rowCheck[ numRows ];
        uint32_t colCheck[ numCols ];
        uint32_t gridCheck[ subBoxSize * subBoxSize ];

        // Process in row-order for better caching
        for( int j = 0; j < numRows; ++j ) {
            for( int i = 0; i < numCols; ++i ) {
                const int bitNum = getBitNum( board[ j ][ i ] );

                const int gridId = ( i / subBoxSize ) + subBoxSize * ( j / subBoxSize ); // Requires integer division. Can't factor
                    
                // Short-circuit. Rows will finish before grids, grids before columns
                // Branch prediction should not expect this condition. When we *do* hit it, the program is done
                const bool valid = isValid( rowCheck[ j ], bitNum  ) && isValid( gridCheck[ gridId ], bitNum ) && isValid( colCheck[ i ], bitNum );
                if( !valid ) {
                    return false;
                }
                // Mark numbers as seen
                markCell( rowCheck[ j ], bitNum );
                markCell( colCheck[ i ], bitNum );
                markCell( gridCheck[ gridId ], bitNum );
            }
        }
        return true;
    }
};
