class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> lut;
        result.reserve( 2 );
        const int listSize = nums.size();
        //lut.reserve( listSize );
        
        for( int i = 0; i < listSize; ++i ) {
            const int num = nums[ i ];
            const int complement = ( target - num );
            auto complementEntry = lut.find( complement );
            if( complementEntry != lut.end() ) {              
                result.push_back( i );
                result.push_back( complementEntry->second );
                return result;
            }
            lut[ num ] = i;
        }
        return result;
    }
};
