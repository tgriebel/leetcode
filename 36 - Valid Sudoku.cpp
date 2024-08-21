class Solution {
    static const int bitMask = ~0x3; // Ascii values are assigned a bit, starts at '.' in ascii for speed
    static const int numRows = 9;
    static const int numCols = 9;
    static const int subBoxSize = 3;

    inline int getNum( const char pieceCode ) {
        const int result = pieceCode - '.'; // Ascii: . / 0 1 2 ... 9
        return result;
    }

    inline int isValid( const int cellCheck, const int cellValue ) {
        return ( cellCheck & ( 1 << cellValue ) & ~0x3 ) == 0;
    }

    inline void markCell( int& cellCheck, const int cellValue ) {
        cellCheck |= ( 1 << cellValue );
    }

public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rowCheck[ numRows ];
        int colCheck[ numCols ];
        int gridCheck[ subBoxSize * subBoxSize ];

        for( int j = 0; j < numRows; ++j ) {
            for( int i = 0; i < numCols; ++i ) {
                const int num = getNum( board[ j ][ i ] );

                const int gridId = ( i / subBoxSize ) + subBoxSize * ( j / subBoxSize );

                if( isValid( rowCheck[ j ], num ) == false ) {
                    return false;
                }
                if( isValid( colCheck[ i ], num ) == false ) {
                    return false;
                }
                if( isValid( gridCheck[ gridId ], num ) == false ) {
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
