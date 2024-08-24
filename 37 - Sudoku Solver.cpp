struct cell_t {
    int x;
    int y;
    set<char> canidates;
};

bool compare( const cell_t* cell0, const cell_t* cell1 ) {
    return ( cell0->canidates.size() < cell1->canidates.size() );
}

class Solution {
public:
    inline static int getBitNum( const char pieceCode ) {
        const int result = pieceCode - '.'; // Ascii: . / 0 1 2 ... 9
        return result;
    }

    inline static bool isValid( const uint32_t cellCheck, const int cellValue ) {
        return !( cellCheck & ( 1 << cellValue ) & ~0x3 );
    }

    inline static void markCell( uint32_t& cellCheck, const int cellValue ) {
        cellCheck |= ( 1 << cellValue );
    }

    int isValidSudoku( vector<vector<char>>& board ) {
        // For each row, column, and subGrid, check if a number was seen before. It's invalid if it was seen
        // Use bitfields, for every possible check, to track if a number was seen 

        uint32_t rowCheck[ 9 ] = {};
        uint32_t colCheck[ 9 ] = {};
        uint32_t gridCheck[ 9 ] = {};

        // Process in row-order for better caching
        for( int j = 0; j < 9; ++j ) {
            for( int i = 0; i < 9; ++i ) {
                const int bitNum = getBitNum( board[ j ][ i ] );

                const int gridId = ( i / 3 ) + 3 * ( j / 3 ); // Requires integer division. Can't factor
                    
                // Short-circuit. Rows will finish before grids, grids before columns
                // Branch prediction should not expect this condition. When we *do* hit it, the program is done
                const bool valid = isValid( rowCheck[ j ], bitNum  ) && isValid( gridCheck[ gridId ], bitNum ) && isValid( colCheck[ i ], bitNum );
                if( !valid ) {
                    return 0;
                }
                // Mark numbers as seen
                markCell( rowCheck[ j ], bitNum );
                markCell( colCheck[ i ], bitNum );
                markCell( gridCheck[ gridId ], bitNum );
            }
        }

        bool isComplete = true;
        for( int i = 0; i < 9; ++i ) {
            // Check if '.' was encountered within any row
            if( ( rowCheck[ i ] & 0x01 ) != 0 ) {
                isComplete = false;
                break;
            }
        }
        return isComplete ? 2 : 1;
    }

    bool isValidCell( vector<vector<char>>& board, const int x, const int y ) {
        uint32_t rowCheck = 0;
        for( int i = 0; i < 9; ++i ) {
            const int bitNum = getBitNum( board[ y ][ i ] );
            if( !isValid( rowCheck, bitNum  ) ) {
                return false;
            }
            markCell( rowCheck, bitNum );
        }

        uint32_t colCheck = 0;
        for( int j = 0; j < 9; ++j ) {
            const int bitNum = getBitNum( board[ j ][ x ] );
            if( !isValid( colCheck, bitNum  ) ) {
                return false;
            }
            markCell( colCheck, bitNum );
        }

        const int boxCornerX = 3 * ( x / 3 );
        const int boxCornerY = 3 * ( y / 3 ); // Requires integer division. Can't factor

        // Remove values from canidate set using the current subbox
        uint32_t boxCheck = 0;
        for( int checkBoxY = boxCornerY; checkBoxY < boxCornerY + 3; ++checkBoxY ) {
            for( int checkBoxX = boxCornerX; checkBoxX < boxCornerX + 3; ++checkBoxX ) {
                const int bitNum = getBitNum( board[ checkBoxY ][ checkBoxX ] );
                if( !isValid( boxCheck, bitNum  ) ) {
                    return false;
                }
                markCell( boxCheck, bitNum );
            }
        }
        return true;
    }

    bool searchSolution( vector<vector<char>>& board, deque<cell_t*>& cells ) {
        if ( cells.empty() ) {
            return true;
        }

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
                
                board[ y ][ x ] = canidate;
                if ( isValidCell( board, x, y ) == 0 ) {
                    board[ y ][ x ] = '.';
                    continue;
                }
                if ( searchSolution( board, cells ) ) {
                    return true;
                }
                board[ y ][ x ] = '.';
            }
            cells.push_front( cell );
            return false; // No canidates worked for cell, bad path
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        deque<cell_t*> cells;

        char values[ 9 ] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

        // Cull invalid canidates
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
                        canidateSet.erase( board[ j ][ checkCol ] );
                    }
                }

                // Remove values from canidate set using the current column
                for( int checkRow = 0; checkRow < 9; ++checkRow ) {
                    if( board[ checkRow ][ i ] != '.' ) {
                        canidateSet.erase( board[ j ][ checkRow ] );
                    }
                }

                const int boxCornerX = 3 * ( i / 3 );
                const int boxCornerY = 3 * ( j / 3 ); // Requires integer division. Can't factor

                // Remove values from canidate set using the current subbox
                for( int checkBoxY = boxCornerY; checkBoxY < boxCornerY + 3; ++checkBoxY ) {
                    for( int checkBoxX = boxCornerX; checkBoxX < boxCornerX + 3; ++checkBoxX ) {
                        if( board[ checkBoxY ][ checkBoxX ] != '.' ) {
                            canidateSet.erase( board[ checkBoxY ][ checkBoxX ] );
                        }
                    }
                }
                cell_t* cell = new cell_t();
                cell->x = i;
                cell->y = j;
                cell->canidates = canidateSet;
                cells.push_back( cell );
            }
        }
        
        sort( cells.begin(), cells.end(), compare );
        searchSolution( board, cells );       
    }
};
