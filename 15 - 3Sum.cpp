class Solution {
public:

    inline int binarySearch( vector<int>& nums, int low, int high, int x )
    {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == x) {
                return mid;
            }

            if (nums[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    inline int scanToUniqueValue( vector<int>& nums, int i ) {
        int j = i + 1;
        while( j < nums.size() && nums[ i ] == nums[ j ] ) {
            ++j;
        }
        return j;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        const int numCount = nums.size();
        
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        result.reserve( numCount );

        int i = 0;

        while( i < numCount - 1 ) {
           int j = i + 1;
           while( j < numCount - 1 ) {
                int complement = -( nums[ i ] + nums[ j ] );       

                // Elements less than j + 1 have already been searched
                int k = binarySearch( nums, j + 1, numCount - 1, complement );
                if( k != -1 ) {
                    result.push_back( vector<int>{ nums[i], nums[j], nums[k] } );       
                }
                j = scanToUniqueValue( nums, j );
           }
           i = scanToUniqueValue( nums, i );
        }
        return result;
    }
};
