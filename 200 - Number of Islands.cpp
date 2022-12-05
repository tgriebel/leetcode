class Solution {
public:
    int mark(vector<vector<char>>& grid, vector<vector<bool>>& marked, int sr, int sc) {
        if( ( sr < 0 ) || ( sc < 0 ) ) {
            return 0;
        }
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
        mark( grid, sr + 1, sc + 0 );
        mark( grid, sr - 1, sc + 0 );
        mark( grid, sr + 0, sc + 1 );
        mark( grid, sr + 0, sc - 1 );
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> marked;
        marked.resize(grid.size());
        for( int i = 0; i < grid.size(); ++ i ) 
            marked.resize(grid[i].size());
        }
        int islandCount = 0;
        for( int j = 0; j < grid.size(); ++ j ) {
            for( int i = 0; i < grid.size(); ++ i ) {
                islandCount += mark( grid, marked, j, i );
            }
        }
        return islandCount;
    }
};
