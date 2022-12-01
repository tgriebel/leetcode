class Solution {
public:
    string intToRoman(int num) {
        static const int numSymbols = 13;
        static const string symbolMap[ numSymbols ] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
        static const int valueMap[ numSymbols ] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
        
        int currentNum = num;
        string asRoman = "";
        asRoman.reserve( 32 );
        for( int i = numSymbols - 1; i >= 0; --i ) {
            const int instances = currentNum / valueMap[ i ];
            const int place = instances * valueMap[ i ];
            
            for( int j = 0; j < instances; ++j ) {
                asRoman += symbolMap[ i ];
            }
            currentNum -= place;
        }
        return asRoman;
    }
};
