class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int bestIndex = -1;
        int minDist = INT_MAX;
        for( int i = 0; i < points.size(); ++i ) {
            if( ( points[i][0] == x ) || ( points[i][1] == y ) ) {
                const int dist = abs( points[i][0] - x ) + abs( points[i][1] - y );
                if( dist < minDist ) {
                    minDist = dist;
                    bestIndex = i;
                }
            }
        }
        return bestIndex;
    }
};
