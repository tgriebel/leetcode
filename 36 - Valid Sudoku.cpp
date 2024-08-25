struct cell_t {
    int x;
    int y;
    set<char> canidates;
};

class ValueMap {
    uint32_t rowBits[ 9 ] = {};
    uint32_t colBits[ 9 ] = {};
    uint32_t boxBits[ 9 ] = {};
};

bool compare( const cell_t* cell0, const cell_t* cell1 ) {
    return ( cell0->canidates.size() < cell1->canidates.size() );
}

class Solution {
public:
    uint32_t rowBits[ 9 ] = {};
    uint32_t colBits[ 9 ] = {};
    uint32_t boxBits[ 9 ] = {};

    int gridIdLut[ 9 ][ 9 ] = {};

    inline static int getBitNum( const char pieceCode ) {
        const int result = pieceCode - '.'; // Ascii: . / 0 1 2 ... 9
        return result;
    }

    inline static bool isValid( const uint32_t cellCheck, const int cellValue ) {
        return !( cellCheck & ( 1 << cellValue ) & ~0x3 );
    }

    inline static void setCellBit( uint32_t& cellCheck, const int cellValue ) {
        cellCheck |= ( 1 << cellValue );
    }

    inline static void clearCellBit( uint32_t& cellCheck, const int cellValue ) {
        cellCheck ^= ( 1 << cellValue );
    }

    inline void buildGridIdLut() {
        for( int j = 0; j < 9; ++j ) {
            for( int i = 0; i < 9; ++i ) {
                gridIdLut[ j ][ i ] = ( i / 3 ) + 3 * ( j / 3 ); // Requires integer division. Can't factor;
            }
        }
    }

    inline int getGridId( const int x, const int y ) {
        return gridIdLut[ y ][ x ];
    }

    bool isValidCell( const vector<vector<char>>& board, const int x, const int y, const char value ) {
        const int gridId = getGridId( x, y );

        const int bitNum = getBitNum( value );

        return isValid( rowBits[ y ], bitNum ) && isValid( colBits[ x ], bitNum ) && isValid( boxBits[ gridId ], bitNum );
    }

    void markCell( vector<vector<char>>& board, const int x, const int y, const char value ) {
        const int gridId = getGridId( x, y );
        
        board[ y ][ x ] = value;

        const int bitNum = getBitNum( board[ y ][ x ] );

        setCellBit( rowBits[ y ], bitNum );
        setCellBit( colBits[ x ], bitNum );
        setCellBit( boxBits[ gridId ], bitNum );
    }

    void clearCell( vector<vector<char>>& board, const int x, const int y ) {
        const int gridId = getGridId( x, y );

        const int bitNum = getBitNum( board[ y ][ x ] );

        clearCellBit( rowBits[ y ], bitNum );
        clearCellBit( colBits[ x ], bitNum );
        clearCellBit( boxBits[ gridId ], bitNum );

        board[ y ][ x ] = '.';
    }

    bool searchSolution( vector<vector<char>>& board, deque<cell_t*>& cells ) {
#ifdef PRINT_BOARD
        for ( int j = 0; j < 9; ++j ) {
            for ( int i = 0; i < 9; ++i ) {
                cout << board[ j ][ i ] << ", ";
            }
            cout << endl;
        }
        cout << endl;
#endif

        while ( cells.empty() == false ) {
            cell_t* cell = cells.front();
            cells.pop_front();

            for ( auto canidate : cell->canidates ) {
                const int x = cell->x;
                const int y = cell->y;

                if ( isValidCell( board, x, y, canidate ) == false ) {
                    continue;
                }
                markCell( board, x, y, canidate );

                if ( cells.empty() ) {
                    return true;
                }
                if ( searchSolution( board, cells ) ) {
                    return true;
                }
                clearCell( board, x, y );
            }
            cells.push_front( cell );
            return false; // No canidates worked for cell, bad path
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        deque<cell_t*> cells;
        vector<cell_t*> cleanupList;

        char values[ 9 ] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

        buildGridIdLut();

        // Prune invalid canidates
        for( int j = 0; j < 9; ++j ) {
            for( int i = 0; i < 9; ++i ) {
                if( board[ j ][ i ] != '.' ) {
                    continue;
                }

                set<char> canidateSet;
                for( int v = 0; v < 9; ++v ) {
                    canidateSet.insert( values[ v ] );
                }

                // Remove values from canidate set using the current row
                for( int checkCol = 0; checkCol < 9; ++checkCol ) {
                    if( board[ j ][ checkCol ] != '.' ) {
                        const int value = board[ j ][ checkCol ];
                        canidateSet.erase( value );
                        markCell( board, checkCol, j, value );
                    }
                }

                // Remove values from canidate set using the current column
                for( int checkRow = 0; checkRow < 9; ++checkRow ) {
                    if( board[ checkRow ][ i ] != '.' ) {
                        const int value = board[ j ][ checkRow ];
                        canidateSet.erase( value );
                        markCell( board, checkRow, j, value );
                    }
                }

                const int boxCornerX = 3 * ( i / 3 );
                const int boxCornerY = 3 * ( j / 3 ); // Requires integer division. Can't factor

                // Remove values from canidate set using the current subbox
                for( int checkBoxY = boxCornerY; checkBoxY < boxCornerY + 3; ++checkBoxY ) {
                    for( int checkBoxX = boxCornerX; checkBoxX < boxCornerX + 3; ++checkBoxX ) {
                        if( board[ checkBoxY ][ checkBoxX ] != '.' ) {
                            const int value = board[ checkBoxY ][ checkBoxX ];
                            canidateSet.erase( value );
                            markCell( board, checkBoxX, checkBoxY, value );
                        }
                    }
                }
                cell_t* cell = new cell_t();
                cell->x = i;
                cell->y = j;
                cell->canidates = canidateSet;
                cells.push_back( cell );
                cleanupList.push_back( cell );
            }
        }
        
        // Presort based on cells with least options
        sort( cells.begin(), cells.end(), compare );
        searchSolution( board, cells );

        for( auto cell : cleanupList ) {
            if( cell != nullptr ) {
                delete cell;
            }
        }
        cleanupList.clear();
    }
};
