class Solution {
public:
    inline string veryLazyIntToString( int count ) {
        string s;

        char onePlace = char( count % 10 + '0' );
        char tenPlace = char( count / 10 + '0' );

        if( count > 9 ) {
            s += tenPlace;
        }
        s += onePlace;

        return s;
    }

    string countAndSay(int n) {
        if( n == 1 ) {
            return "1";
        }
        string sequence = countAndSay( n - 1 );
   
        // RLE
        string rle;
        int left = 0;
        int right = 1;
        int count = 1;

        while( left < sequence.size() ) {
            if( sequence[ left ] == sequence[ right ] && ( right < sequence.size() ) ) {
                ++count;
            } else {
                rle += veryLazyIntToString( count );
                rle += sequence[ left ];
              
                left = right;
                count = 1;
            }
            ++right;
        }    
        return rle;
    }
};
