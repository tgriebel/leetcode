class Solution {
public:
    inline void searchPalindrome( string s, int l, int r, int& offset, int& maxLength ) {
        while( l >= 0 && r < s.size() ) {
            if( s[ l ] != s[ r ] ) {
                return;
            }
            const int length = ( r - l ) + 1;
            if( length > maxLength ) {
                maxLength = length;
                offset = l;
            }
            --l;
            ++r;
        }
    }

    string longestPalindrome(string s) {
        if( s.size() == 1 ) {
            return s;
        }

        int maxLength = 1;
        int offset = 0;

        for( int center = 1; center < s.size(); ++center ) {
            int l = 0;
            int r = 0;

            l = center - 1;
            r = center;

            searchPalindrome( s, l, r, offset, maxLength );

            l = center - 1;
            r = center + 1;
            searchPalindrome( s, l, r, offset, maxLength );
        }
        return s.substr( offset, maxLength );
    }
};
