class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lastFree = 0;
        for( int i = 0; i < nums.size(); ++i ) {
            if( nums[ i ] != val ) {
                nums[ lastFree ] = nums[ i ];
                lastFree++;
            }
        }
        return lastFree;
    }
};
