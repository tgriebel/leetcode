class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_map<char, int> repeats; // <character, last index>

        int left = 0;
        for( int right = 0; right < s.length(); ++right ) {
            const char c = s[ right ];
            if( repeats.find( c ) != repeats.end() && repeats[ c ] >= left ) { // Has the character
                // compare length
                maxLength = max( maxLength, right - left );
                // move to next location
                left = repeats[ c ] + 1;
            } else {
                maxLength = max( maxLength, right - left + 1 );
            }
            repeats[ c ] = right; // update to new location
        }
        return maxLength;
    }
};
