class Solution {
    int getNum( const char pieceCode ) {
        const int result = pieceCode - '0';
        if( result >= 1 && result <= 9 ) {
            return result;
        }
        return 0;
    }

    int isValid( const int cellCheck, const int cellValue ) {
        return ( cellCheck & ( 1 << cellValue ) & ~0x01 ) == 0;
    }

    void markCell( int& cellCheck, const int cellValue ) {
        cellCheck |= ( 1 << cellValue );
    }

public:
    bool checkSquare( vector<vector<char>>& board, int x, int y ) {
        const int numRows = board.size();
        const int numCols = board[ 0 ].size();

        const int subBoxSize = 3;

        if( y + 3 > numRows ) {
            return false;
        }
        if( x + 3 > numCols ) {
            return false;
        }

        int numCheck = 0;
        for( int j = y; j < (y + subBoxSize); ++j ) {
            for( int i = x; i < (x + subBoxSize); ++i ) {
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
        const int numRows = board.size();
        const int numCols = board[ 0 ].size();

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
