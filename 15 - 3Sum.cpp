class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        // sort array so we know numbers are monotonic
        sort( nums.begin(), nums.end() );

        // scan to line between positives/negatives 
        int i = 0;
        while( nums[ i ] < 0 ) {
            ++i;
        }

        // All positive or negative. Can't have three 0's
        if( i == 0 || i == nums.size() ) {
            return result;
        }

        int left = i - 1;
        int middel = i;
        int right = i + 1;

        return result;
    }
};
