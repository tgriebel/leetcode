class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastUnique = 0;
        for( int i = 1; i < nums.size(); ++i ) {
            if( nums[ i ] != nums[ lastUnique ] ) {
                nums[ lastUnique + 1 ] = nums[ i ];
                lastUnique++;
            }
        }
        return lastUnique + 1;
    }
};
