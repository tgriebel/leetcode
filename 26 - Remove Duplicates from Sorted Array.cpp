class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastUnique = 0;
        const int size = static_cast<int>( nums.size() );

        for( int i = 1; i < size; ++i ) {
            if( nums[ i ] != nums[ lastUnique ] ) {
                nums[ lastUnique + 1 ] = nums[ i ];
                lastUnique++;
            }
        }
        return lastUnique + 1;
    }
};
