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
    int Visit(vector<vector<int>>& grid, vector<vector<int>>& marked, int sr, int sc) {
        if( sr >= grid.size() ) {
            return INT_MAX;
        }
        if( sc >= grid[sr].size() ) {
            return INT_MAX;
        }

        const int N = ( grid.size() - 1 );
        if( ( sr == N ) && ( sc == N ) ) {
            return 1;
        }

        if( ( grid[sr][sc] == 1 ) || marked[sr][sc] ) {
            return INT_MAX;
        }

        marked[sr][sc] = 1;
        const int c00 = Visit( grid, marked, sr - 1, sc - 1 );
        const int c01 = Visit( grid, marked, sr - 1, sc + 0 );
        const int c02 = Visit( grid, marked, sr - 1, sc + 1 );
        const int c10 = Visit( grid, marked, sr + 0, sc - 1 );
        const int c12 = Visit( grid, marked, sr + 0, sc + 1 );
        const int c20 = Visit( grid, marked, sr + 1, sc - 1 );
        const int c21 = Visit( grid, marked, sr + 1, sc + 0 );
        const int c22 = Visit( grid, marked, sr + 1, sc + 1 );
        
        int minTop = min( c00, c01 );
        minTop = min( minTop, c02 );

        int minBottom = min( c20, c21 );
        minBottom = min( minBottom, c22 );

        int minPath = min( c10, c12 );
        minPath = min( minPath, minTop );
        minPath = min( minPath, minBottom );
        
        return ( minPath == INT_MAX ) ? INT_MAX :( minPath + 1 );
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const point_t offsets[8] = { point_t( -1, -1 ),
                                     point_t( 0, -1 ),
                                     point_t( 1, -1 ),
                                     point_t( -1, 0 ),
                                     point_t( 1, 0 ),
                                     point_t( -1, 1 ),
                                     point_t( 0, 1 ),
                                     point_t( 1, 1 ) };

        const int N = grid.size() - 1;
        if( ( grid[0][0] == 1 ) || ( grid[N][N] == 1 ) ) {
            return -1;
        }

        struct node_t {
            point_t pt;
            int depth;
            node_t( const point_t pt, const int depth ) : pt( pt ), depth( depth ) {}
        };

        set<point_t> visited;
        queue<node_t> cells;

        cells.push( node_t( point_t( 0, 0 ), 0 ) );
        visited.insert( cells.back().pt );

        int minPath = INT_MAX;

        while( !cells.empty() ) {
            const node_t current = cells.front();
            cells.pop();

            if( ( current.pt.x == N ) && ( current.pt.y == N ) ) {
                minPath = min( minPath, current.depth + 1 );
                continue;
            }
  
            for( int i = 0; i < 8; ++i ) {
                const point_t next = current.pt + offsets[i];
                if( InGrid( grid, next ) == false ) {
                    continue;
                }
                if( visited.find( next ) != visited.end() ) {
                    continue;
                }
                if( grid[next.y][next.x] == 1 ) {
                    continue;
                }
                visited.insert( next );
                cells.push( node_t( next, current.depth + 1 ) );
            }
        }
        return ( minPath == INT_MAX ) ? -1 : minPath;
    }
};
