struct point_t {
    int x;
    int y;
    point_t() : x(0), y(0) {}
    point_t( const int x, const int y) : x(x), y(y) {}

    point_t operator+( const point_t& pt ) const {
        return point_t( x + pt.x, y + pt.y);
    }

    point_t operator-( const point_t& pt ) const {
        return point_t( x - pt.x, y - pt.y);
    }

    bool operator==( const point_t& pt ) const {
        return ( x == pt.x ) && ( y == pt.y );
    }

    bool operator!=( const point_t& pt ) const {
        return ( x != pt.x ) || ( y != pt.y );
    }

    bool operator<( const point_t& pt ) const {
        if ( x < pt.x ) {
            return true;
        } else if ( pt.x < x ) {
            return false;
        } else {
            return ( y < pt.y );
        }
    }
};

struct node_t {
    point_t pt;
    int depth;
    node_t( const point_t pt, const int depth ) : pt( pt ), depth( depth ) {}
};

static const int offsetCount = 4;
static const point_t offsets[offsetCount] = { point_t( 0, -1 ),
                                              point_t( -1, 0 ),
                                              point_t( 1, 0 ),
                                              point_t( 0, 1 ) };

class Solution {    void ClearGrid( vector<vector<int>>& grid, const int value ) {
        for( int r = 0; r < grid.size(); ++r ) {
            for( int c = 0; c < grid[r].size(); ++c ) {
                grid[r][c] = value;
            }
        }
    }

    inline bool InGrid( const vector<vector<int>>& grid, const point_t pt ) {
        if( pt.y >= grid.size() ) {
            return false;
        }
        if( pt.x >= grid[0].size() ) {
            return false;
        }
        return true;
    }

    point_t FindFirstIslandCell( const vector<vector<int>>& grid ) {
        for( int r = 0; r < grid.size(); ++r ) {
            for( int c = 0; c < grid[r].size(); ++c ) {
                if( grid[r][c] == 1 ) {
                    return point_t( c, r );
                }
            }
        }
        return point_t( -1, -1 );
    }

    void FindBeaches( const vector<vector<int>>& grid, queue<node_t>& beachCells, set<point_t>& visited ) {
        const point_t island = FindFirstIslandCell( grid );
        if( ( island.x < 0 ) || ( island.y < 0 ) ) {
            return;
        }
        
        queue<node_t> cells;

        cells.push( node_t( island, 0 ) );
        visited.insert( island );

        while( !cells.empty() ) {
            const node_t current = cells.front();
            cells.pop();

            bool isBeach = false;
            for( int i = 0; i < 4; ++i ) {
                const point_t next = current.pt + offsets[i];
                if( InGrid( grid, next ) == false ) {
                    continue;
                }
                if( grid[next.y][next.x] == 0 ) {
                    isBeach = true;
                    continue;
                }
                if( visited.find( next ) != visited.end() ) {
                    continue;
                }
                visited.insert( next );
                cells.push( node_t( next, current.depth + 1 ) );
            }
            if( isBeach ) {
                beachCells.push( node_t( current.pt, 0 ) );
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        set<point_t> visited;
        queue<node_t> cells;

        FindBeaches( grid, cells, visited );

        int minPath = INT_MAX;

        while( !cells.empty() ) {
            const node_t current = cells.front();
            cells.pop();

            // All starting cells are islands with depth 0, we want islands that are end points
            if( ( grid[current.pt.y][current.pt.x] == 1 ) && ( current.depth > 0 ) ) {
                minPath = min( minPath, current.depth - 1 );
                continue;
            }
  
            for( int i = 0; i < offsetCount; ++i ) {
                const point_t next = current.pt + offsets[i];
                if( InGrid( grid, next ) == false ) {
                    continue;
                }
                if( visited.find( next ) != visited.end() ) {
                    continue;
                }
                visited.insert( next );
                cells.push( node_t( next, current.depth + 1 ) );
            }
        }
        return minPath;
    }
};
