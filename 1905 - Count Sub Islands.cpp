class Solution {
public:
    int visit(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& marked, int sr, int sc) {
        if( ( sr < 0 ) || ( sc < 0 ) ) {
            return false;
        }
        if( sr >= grid2.size() ) {
            return 0;
        }
        if( sc >= grid2[sr].size() ) {
            return 0;
        }
        if( ( grid2[sr][sc] == 0 ) || marked[sr][sc] ) {
            return 0;
        }
        marked[sr][sc] = 1;
        const int rightCell = visit( grid1, grid2, marked, sr + 1, sc + 0 );
        const int leftCell = visit( grid1, grid2, marked, sr - 1, sc + 0 );
        const int upperCell = visit( grid1, grid2, marked, sr + 0, sc + 1 );
        const int lowerCell = visit( grid1, grid2, marked, sr + 0, sc - 1 );
        if( ( rightCell < 0 ) || ( leftCell < 0 ) || ( upperCell < 0 ) || ( lowerCell < 0 ) ) {
            return -1;
        }
        if( grid1[sr][sc] != grid2[sr][sc] ) {
            return -1;
        }
        return ( 1 + rightCell + leftCell + upperCell + lowerCell );
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>> marked;
        marked.resize(grid1.size());
        for( int r = 0; r < grid1.size(); ++r ) {
            marked[r].resize(grid1[r].size());
        }
        for( int r = 0; r < grid1.size(); ++r ) {
            for( int c = 0; c < grid1[r].size(); ++c ) {
                marked[r][c] = 0;
            }
        }
        int subIslandCount = 0;
        for( int r = 0; r < grid1.size(); ++r ) {
            for( int c = 0; c < grid1[r].size(); ++c ) {
                const int count = visit( grid1, grid2, marked, r, c );
                if( count >= 1 ) {
                    ++subIslandCount;
                }
            }
        }
        return subIslandCount;
    }
};
