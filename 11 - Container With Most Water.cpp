class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;

        while( left < right ) {
            const int w = ( right - left );
            const int h = min( height[right], height[left] );
            const int currentMax = w * h;
            maxArea = max( maxArea, currentMax );
            
            if( height[ left ] > height[ right ] ) {
                --right;
            } else if( height[ right ] > height[ left ] ) {
                ++left;
            } else {
                ++left;
                --right;
            }
        }
        return maxArea;
    }
};
