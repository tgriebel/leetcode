class Solution {
public:
    bool isPalindrome(int x) {
        char asString[ 32 ];
        sprintf( asString, "%i", x );
        const int length = strlen( asString );
        
        int left = 0;
        int right = length - 1;
        while( left <= right ) {
            if( asString[ left ] != asString[ right ] ) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
