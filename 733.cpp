class Solution {
public:
    inline bool isValid(vector<vector<int>>& image, int sr, int sc, int targetColor, int replaceColor) {
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
        if( sr >= image.size() ) {
            return;
        }
        if( sc >= image[sr].size() ) {
            return;
        }
        if( ( image[sr][sc] != targetColor ) || ( image[sr][sc] == replaceColor ) ) {
            return;
        }
        image[sr][sc] = replaceColor;
        fill( image, sr + 1, sc + 0, targetColor, replaceColor );
        fill( image, sr - 1, sc + 0, targetColor, replaceColor );
        fill( image, sr + 0, sc + 1, targetColor, replaceColor );
        fill( image, sr + 0, sc - 1, targetColor, replaceColor );
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> filledImage = image;
        fill( filledImage, sr, sc, filledImage[sr][sc], color );
        return filledImage;
    }
};