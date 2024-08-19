class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> duplicates;

        vector<int> result;
        result.reserve( (int) nums.size() );

        for( int i = 0; i < nums.size(); ++i ) {
            if( duplicates.find( nums[ i ] ) == duplicates.end() ) {
                result.push_back( nums[ i ] );
            }
            duplicates.insert( nums[ i ] );
        }

        nums = result;
        return (int)result.size();
    }
};
