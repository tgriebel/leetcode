class Solution {
public:
    int longestWPI(vector<int>& hours) {    
        int runningSum = 0;
        int longestInterval = 0;

       unordered_map<int,int> map;

        for( int i = 0; i < hours.size(); ++i ) {
            // Score +/-1 based on comparison
            // A negative sum means there are fewer days with hours below 8; positive means there are more days above 8
            const int delta = ( hours[ i ] > 8 ) ? 1 : -1;
            runningSum += delta;

            if( runningSum > 0 ) {
              // It's a running sum so we are guaranteed that [0, i] is WPI
              // This is the straight-forward case
              longestInterval = i + 1;
            } else {
                // An ideal interval will have a balance close to zero so an interval can contain negatives
                // Even if the global running sum is negative there may be a local positive sum
                // This local sum can be found by finding the first occurance of the current negative sum
                // The sum can then be adjusted from that point
              
                // Track the earliest occurance of this negative value. This can be used as an offset
                if( map.find( runningSum ) == map.end() ) {
                    map[ runningSum ] = i;
                } 
                // Offsets the balance so we have a +1 score by finding the earliest score more negative
                if( map.find( runningSum - 1 ) != map.end() ) {
                    longestInterval = max( longestInterval, i - map[ runningSum - 1 ] );
                }
            }
        }
        return longestInterval;
    }
};
