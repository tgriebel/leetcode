class Solution {
    int generation;
public:
    enum outlet_t {
        NONE = 0,
        PACIFIC = 1,
        ATLANTIC = 2,
        BOTH = 3,
    };

    outlet_t Visit( vector<vector<int>>& heights, vector<vector<int>>& path, vector<vector<int>>& marked, int sr, int sc, int sh ) {
        if( ( sr < 0 ) || ( sc < 0 ) ) {
            return PACIFIC;
        }
        if( ( sr >= heights.size() ) || ( sc >= heights[sr].size() ) ) {
            return ATLANTIC;
        }
        if( heights[sr][sc] > sh ) {
            return NONE;
        }
        if( marked[sr][sc] >= generation ) {
            return NONE;
        }

        marked[sr][sc] = generation;
        const outlet_t rightCell = Visit( heights, path, marked, sr + 0, sc + 1, heights[sr][sc] );
        const outlet_t leftCell = Visit( heights, path, marked, sr + 0, sc - 1, heights[sr][sc] );
        const outlet_t bottomCell = Visit( heights, path, marked, sr + 1, sc + 0, heights[sr][sc] );
        const outlet_t topCell = Visit( heights, path, marked, sr - 1, sc + 0, heights[sr][sc] );

        const outlet_t outlet = outlet_t( rightCell | leftCell | bottomCell | topCell );
        return outlet;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> marked;
        marked.resize(heights.size());
        for( int r = 0; r < heights.size(); ++r ) {
            marked[r].resize(heights[r].size());
        }
        for( int r = 0; r < heights.size(); ++r ) {
            for( int c = 0; c < heights[r].size(); ++c ) {
                marked[r][c] = 0;
            }
        }
        vector<vector<int>> path;
        generation = 1;
        for( int r = 0; r < heights.size(); ++r ) {
            for( int c = 0; c < heights[r].size(); ++c ) {
                outlet_t result = Visit( heights, path, marked, r, c, heights[r][c] );
                if( result == BOTH ) {
                    vector<int> cell{ r, c };
                    path.push_back( cell );
                }
                ++generation;
            }
        }
        return path;
    }
};
