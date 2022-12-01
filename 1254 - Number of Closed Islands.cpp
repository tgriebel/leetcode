class Solution {
public:
    int visit(vector<vector<int>>& grid, vector<vector<int>>& marked, int sr, int sc) {
        if( sr >= grid.size() ) {
            return -1;
        }
        if( sc >= grid[sr].size() ) {
            return -1;
        }
        if( ( grid[sr][sc] == 1 ) || marked[sr][sc] ) {
            return 0;
        }
        marked[sr][sc] = 1;
        const int rightCell = visit( grid, marked, sr + 1, sc + 0 );
        const int leftCell = visit( grid, marked, sr - 1, sc + 0 );
        const int upperCell = visit( grid, marked, sr + 0, sc + 1 );
        const int lowerCell = visit( grid, marked, sr + 0, sc - 1 );
        if( ( rightCell < 0 ) || ( leftCell < 0 ) || ( upperCell < 0 ) || ( lowerCell < 0 ) ) {
            return -1;
        }
        return 1;
    }
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> marked;
        marked.resize(grid.size());
        for( int r = 0; r < grid.size(); ++r ) {
            marked[r].resize(grid[r].size());
        }
        for( int r = 0; r < grid.size(); ++r ) {
            for( int c = 0; c < grid[r].size(); ++c ) {
                marked[r][c] = 0;
            }
        }
        int closedCount = 0;
        for( int r = 0; r < grid.size(); ++r ) {
            for( int c = 0; c < grid[r].size(); ++c ) {
                if( visit( grid, marked, r, c ) == 1 ) {
                    ++closedCount;
                }
            }
        }
        return closedCount;
    }
};
