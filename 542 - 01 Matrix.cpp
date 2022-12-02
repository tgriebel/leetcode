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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const point_t offsets[4] = { point_t( 0, -1 ),
                                     point_t( -1, 0 ),
                                     point_t( 1, 0 ),
                                     point_t( 0, 1 ) };

        struct node_t {
            point_t pt;
            int depth;
            node_t( const point_t pt, const int depth ) : pt( pt ), depth( depth ) {}
        };

        set<point_t> visited;
        queue<node_t> cells;

        const int N = mat.size() - 1;
        vector<vector<int>> paths;
        paths.resize( mat.size() );

        for( int r = 0; r < mat.size(); ++r ) {
            paths[r].resize( mat[r].size() );
            for( int c = 0; c < mat[r].size(); ++c ) {
                if( mat[r][c] == 0 ) {
                    cells.push( node_t( point_t( c, r ), 0 ) );
                    visited.insert( cells.back().pt );
                }
            }
        }

        int minPath = INT_MAX;

        while( !cells.empty() ) {
            const node_t current = cells.front();
            cells.pop();

            paths[current.pt.y][current.pt.x] = current.depth;
  
            for( int i = 0; i < 4; ++i ) {
                const point_t next = current.pt + offsets[i];
                if( InGrid( mat, next ) == false ) {
                    continue;
                }
                if( visited.find( next ) != visited.end() ) {
                    continue;
                }
                visited.insert( next );
                cells.push( node_t( next, current.depth + 1 ) );
            }
        }
        return paths;
    }
};
