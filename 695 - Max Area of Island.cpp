class Solution {
public:
    int visit(vector<vector<int>>& grid, vector<vector<bool>>& marked, int sr, int sc) {
        if( sr >= grid.size() ) {
            return 0;
        }
        if( sc >= grid[sr].size() ) {
            return 0;
        }
        if( ( grid[sr][sc] == 0 ) || marked[sr][sc] ) {
            return 0;
        }
        marked[sr][sc] = true;
        int cellCount = 1;
        cellCount += visit( grid, marked, sr + 1, sc + 0 );
        cellCount += visit( grid, marked, sr - 1, sc + 0 );
        cellCount += visit( grid, marked, sr + 0, sc + 1 );
        cellCount += visit( grid, marked, sr + 0, sc - 1 );
        return cellCount;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> marked;
        marked.resize(grid.size());
        for( int r = 0; r < grid.size(); ++r ) {
            marked[r].resize(grid[r].size());
        }
        for( int r = 0; r < grid.size(); ++r ) {
            for( int c = 0; c < grid[r].size(); ++c ) {
                marked[r][c] = false;
            }
        }
        int islandMax = 0;
        for( int r = 0; r < grid.size(); ++r ) {
            for( int c = 0; c < grid[r].size(); ++c ) {
                islandMax = max( islandMax, visit( grid, marked, r, c ) );
            }
        }
        return islandMax;
    }
};
