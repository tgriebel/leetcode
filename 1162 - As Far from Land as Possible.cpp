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

class Solution {
    void ClearGrid( vector<vector<int>>& grid, const int value ) {
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

public:
    int maxDistance( vector<vector<int>>& grid ) {
        const point_t offsets[4] = { point_t( 1, 0 ),
                                     point_t( -1, 0 ),
                                     point_t( 0, -1 ),
                                     point_t( 0, 1 ) };

        set<point_t> visited;
        queue<point_t> cells;

        for( int r = 0; r < grid.size(); ++r ) {
            for( int c = 0; c < grid[r].size(); ++c ) {
                if( grid[r][c] == 1 ) {
                    cells.push( point_t( c, r ) );
                    visited.insert( cells.back() );
                }
            }
        }

        if( ( cells.size() == 0 ) || ( cells.size() == grid.size() * grid.size() ) ) {
            return -1;
        }

        int maxPath = 0;
        int depth = 0;
        int nodesProcessed = 0;
        int nodesAtDepth = cells.size();
        int minPath = INT_MAX;

        while( !cells.empty() ) {
            const point_t current = cells.front();
            cells.pop();

            ++nodesProcessed;
            if( nodesProcessed > nodesAtDepth ) {
                nodesProcessed = 0;
                nodesAtDepth = cells.size();
                ++depth;
            }

            maxPath = max( maxPath, depth );
            
            for( int i = 0; i < 4; ++i ) {
                const point_t next = current + offsets[i];
                if( InGrid( grid, next ) == false ) {
                    continue;
                }
                if( visited.find( next ) != visited.end() ) {
                    continue;
                }
                visited.insert( next );
                cells.push( next );
            }
        }
        return maxPath;
    }
};
