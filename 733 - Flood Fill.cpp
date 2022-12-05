class Solution {
public:
    inline bool isValid(vector<vector<int>>& image, int sr, int sc, int targetColor, int replaceColor) {
        if( ( sr < 0 ) || ( sc < 0 ) ) {
            return false;
        }
        if( sr >= image.size() ) {
            return false;
        }
        if( sc >= image[sr].size() ) {
            return false;
        }
        if( ( image[sr][sc] != targetColor ) || ( image[sr][sc] == replaceColor ) ) {
            return false;
        }
        return true;
    }
    void fill(vector<vector<int>>& image, int sr, int sc, int targetColor, int replaceColor) {
        image[sr][sc] = replaceColor;
        if( isValid( image, sr + 1, sc + 0, targetColor, replaceColor ) ) {
            fill( image, sr + 1, sc + 0, targetColor, replaceColor );
        }
        if( isValid( image, sr - 1, sc + 0, targetColor, replaceColor ) ) {
            fill( image, sr - 1, sc + 0, targetColor, replaceColor );
        }
        if( isValid( image, sr + 0, sc + 1, targetColor, replaceColor ) ) {
            fill( image, sr + 0, sc + 1, targetColor, replaceColor );
        }
        if( isValid( image, sr + 0, sc - 1, targetColor, replaceColor ) ) {
            fill( image, sr + 0, sc - 1, targetColor, replaceColor );
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> filledImage = image;
        fill( filledImage, sr, sc, filledImage[sr][sc], color );
        return filledImage;
    }
};
