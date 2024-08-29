struct cell_t {
    uint16_t x;
    uint16_t y;
	set<char>::iterator candidateItt;
    set<char> candidates;
};

class ValueMap {
private:
    static const int BoardSize = 9;
    static const int BoxSize = 3;

    // 16bit for cache line efficiency
    uint16_t rowBits[ BoardSize ];
    uint16_t colBits[ BoardSize ];
    uint16_t boxBits[ BoardSize ];

    uint16_t gridIdLut[ BoardSize ][ BoardSize ] = {};

    inline static int getBitNum( const char pieceCode ) {
        const int result = pieceCode - '.'; // Ascii: . / 0 1 2 ... 9
        return result;
    }

    inline int getGridId( const int x, const int y ) {
        return gridIdLut[ y ][ x ];
    }

    inline static bool isValid( const uint16_t cellCheck, const int cellValue ) {
        return !( cellCheck & ( 1 << cellValue ) & ~0x3 );
    }

    inline static void setCellBit( uint16_t& cellCheck, const int cellValue ) {
        cellCheck |= ( 1 << cellValue );
    }

    inline static void clearCellBit( uint16_t& cellCheck, const int cellValue ) {
        cellCheck ^= ( 1 << cellValue );
    }

public:
    ValueMap() {
        // Build grid ID LUT
        for( int j = 0; j < BoardSize; ++j ) {
            for( int i = 0; i < BoardSize; ++i ) {
                gridIdLut[ j ][ i ] = ( i / BoxSize ) + BoxSize * ( j / BoxSize ); // Requires integer division. Can't factor;
            }
        }
        Reset();
    }

    void Reset() {
        memset( rowBits, 0, BoardSize * sizeof( rowBits[ 0 ] ) );
        memset( colBits, 0, BoardSize * sizeof( colBits[ 0 ] ) );
        memset( boxBits, 0, BoardSize * sizeof( boxBits[ 0 ] ) );
    }

    bool isValidCell( const int x, const int y, const char value ) {
        const int gridId = getGridId( x, y );
        const int bitNum = getBitNum( value );

        return isValid( rowBits[ y ], bitNum ) && isValid( colBits[ x ], bitNum ) && isValid( boxBits[ gridId ], bitNum );
    }

    void markCell( const int x, const int y, const char value ) {
        const int gridId = getGridId( x, y );    
        const int bitNum = getBitNum( value );

        setCellBit( rowBits[ y ], bitNum );
        setCellBit( colBits[ x ], bitNum );
        setCellBit( boxBits[ gridId ], bitNum );
    }

    void clearCell( const int x, const int y, const char value ) {
        const int gridId = getGridId( x, y );
        const int bitNum = getBitNum( value );

        clearCellBit( rowBits[ y ], bitNum );
        clearCellBit( colBits[ x ], bitNum );
        clearCellBit( boxBits[ gridId ], bitNum );
    }
};

bool compare( const cell_t* cell0, const cell_t* cell1 ) {
    return ( cell0->candidates.size() < cell1->candidates.size() );
}

class Solution {
public:
    static constexpr char values[ 9 ] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

    ValueMap valueMap;

    static void printBoard( const vector<vector<char>>& board ) {
        for ( int j = 0; j < 9; ++j ) {
            for ( int i = 0; i < 9; ++i ) {
                cout << board[ j ][ i ] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
	
	bool searchSolutionNonRecursive() {
        deque<cell_t*> visited;
    
        while ( cells.empty() == false ) {
            cell_t* cell = cells.front();
            cells.pop_front();

            while ( cell->candidateItt != cell->candidates.end() ) {
                const int x = cell->x;
                const int y = cell->y;
                const char candidate = *cell->candidateItt;

                if ( valueMap.isValidCell( x, y, candidate ) == false ) {
                    ++cell->candidateItt;
                    continue;
                }
                board[ y ][ x ] = candidate;
                valueMap.markCell( x, y, candidate );

                // All cells have valid candidates places
                if ( cells.empty() ) {
                    return true;
                }

                // Restart search for next node
                cell_t* nextCell = cells.front();
                nextCell->candidateItt = nextCell->candidates.begin();
                break;
            }
    
            // Search failed for cell, back-track
            if ( cell->candidateItt == cell->candidates.end() ) {
                const int x = cell->x;
                const int y = cell->y;

                valueMap.clearCell( x, y, board[ y ][ x ] );
                board[ y ][ x ] = '.';

                //cell->candidateItt = cell->candidates.begin();
                cells.push_front( cell );

                if ( visited.empty() == false ) {
                    cell_t* visitedCell = visited.front();

                    // Try the next candidate
                    if ( visitedCell->candidateItt != visitedCell->candidates.end() ) {
                        ++visitedCell->candidateItt; 
                    }

                    valueMap.clearCell( visitedCell->x, visitedCell->y, board[ visitedCell->y ][ visitedCell->x ] );
                    board[ visitedCell->y ][ visitedCell->x ] = '.';

                    cells.push_front( visitedCell );
                    visited.pop_front();
                } else {
                    return false;
                }
            } else {
                visited.push_front( cell );
            }
        }
    }

    bool searchSolution( vector<vector<char>>& board, deque<cell_t*>& cells ) {
#ifdef PRINT_BOARD
        printBoard( board );
#endif

        while ( cells.empty() == false ) {
            cell_t* cell = cells.front();
            cells.pop_front();

            for ( auto candidate : cell->candidates ) {
                const int x = cell->x;
                const int y = cell->y;

                if ( valueMap.isValidCell( x, y, candidate ) == false ) {
                    continue;
                }
                board[ y ][ x ] = candidate;
                valueMap.markCell( x, y, candidate );

                if ( cells.empty() ) {
                    return true;
                }
                if ( searchSolution( board, cells ) ) {
                    return true;
                }
                valueMap.clearCell( x, y, candidate );
                board[ y ][ x ] = '.';
            }
            cells.push_front( cell );
            return false; // No candidates worked for cell, bad path
        }
        return false;
    }

    void solveSudoku( vector<vector<char>>& board ) {
        deque<cell_t*> cells;
        vector<cell_t*> cleanupList;

        // Find unsolved cells
        for( int j = 0; j < 9; ++j ) {
            for( int i = 0; i < 9; ++i ) {
                if( board[ j ][ i ] != '.' ) {
                    valueMap.markCell( i, j, board[ j ][ i ] );
                    continue;
                }           
                cell_t* cell = new cell_t();
                cell->x = i;
                cell->y = j;
                
                cells.push_back( cell );
                cleanupList.push_back( cell );
            }
        }

        // Populate candidate lists for unsolved cells
        for( auto cell : cells ) {
            for( int v = 0; v < 9; ++v ) {
                if( valueMap.isValidCell( cell->x, cell->y, values[ v ] ) ) {
                    cell->candidates.insert( values[ v ] );
                }
            }
        }
        
        // Presort based on cells with least options
        sort( cells.begin(), cells.end(), compare );
        searchSolution( board, cells );

        // Clean-up
        for( auto cell : cleanupList ) {
            if( cell != nullptr ) {
                delete cell;
            }
        }
        cleanupList.clear();
    }
};
