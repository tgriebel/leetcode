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
    bool checkSquare( vector<vector<char>>& board, int x, int y ) {
        const int subBoxEndX = (x + subBoxSize);
        const int subBoxEndY = (y + subBoxSize);

        int numCheck = 0;
        for( int j = y; j < subBoxEndY; ++j ) {
            for( int i = x; i < subBoxEndX; ++i ) {
                const int num = getNum( board[ j ][ i ] );
                if( isValid( numCheck, num ) == false ) {
                    return false;
                }
                markCell( numCheck, num );
            }
        }
        return true;
    }

    bool checkRows( vector<vector<char>>& board ) {
        for( int j = 0; j < numRows; ++j ) {
            int numCheck = 0;
            for( int i = 0; i < numCols; ++i ) {
                const int num = getNum( board[ j ][ i ] );
                if( isValid( numCheck, num ) == false ) {
                    return false;
                }
                markCell( numCheck, num );
            }
        }
        return true;
    }

    bool checkColumns( vector<vector<char>>& board ) {
        const int numRows = board.size();
        const int numCols = board[ 0 ].size();

        for( int i = 0; i < numCols; ++i ) {
            int numCheck = 0;
            for( int j = 0; j < numRows; ++j ) {
                const int num = getNum( board[ j ][ i ] );
                if( isValid( numCheck, num ) == false ) {
                    return false;
                }
                markCell( numCheck, num );
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        bool squareCheck = checkSquare( board, 0, 0 );
        squareCheck = squareCheck && checkSquare( board, 0, 3 );
        squareCheck = squareCheck && checkSquare( board, 0, 6 );
        squareCheck = squareCheck && checkSquare( board, 3, 0 );
        squareCheck = squareCheck && checkSquare( board, 3, 3 );
        squareCheck = squareCheck && checkSquare( board, 3, 6 );
        squareCheck = squareCheck && checkSquare( board, 6, 0 );
        squareCheck = squareCheck && checkSquare( board, 6, 3 );
        squareCheck = squareCheck && checkSquare( board, 6, 6 );

        return checkRows( board ) && checkColumns( board ) && squareCheck;
    }
};
