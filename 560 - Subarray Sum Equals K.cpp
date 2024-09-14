class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
#define BUTE_FORCE 0
#if BUTE_FORCE
        for( int start = 0; start < nums.size(); ++start ) {
            int sum = 0;
            for( int i = start; i < nums.size(); ++i ) {               
                sum += nums[ i ];
                if( sum == k ) {
                    ++count;
                }
            }
        }
#else
        vector<int> prefixSum;
        prefixSum.resize( nums.size() );

        prefixSum[ 0 ] = nums[ 0 ];
        for( int i = 1; i < nums.size(); ++i ) {
            prefixSum[ i ] = prefixSum[ i - 1 ] + nums[ i ];
        }

        unordered_map<int, int> subArrayStarts;
        for( int i = 0; i < prefixSum.size(); ++i ) {
            if( prefixSum[ i ] == k ) {
                ++count;
            }
            const int complement = prefixSum[ i ] - k;
            if( subArrayStarts.find( complement ) != subArrayStarts.end() ) {
                count += subArrayStarts[ complement ];
            }
            subArrayStarts[ prefixSum[ i ] ]++;
        }
#endif
        return count;
    }
};
