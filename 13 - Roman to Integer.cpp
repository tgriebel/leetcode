class Solution {
public:    
    int romanToInt(string s) {        
        unordered_map<string,int> romanToValue;
        romanToValue[ "I"] = 1;
        romanToValue[ "V" ] = 5;
        romanToValue[ "X" ] = 10;
        romanToValue[ "L" ] = 50;
        romanToValue[ "C" ] = 100;
        romanToValue[ "D" ] = 500;
        romanToValue[ "M" ] = 1000;
        
        romanToValue[ "IV" ] = 4;
        romanToValue[ "IX" ] = 9;
        romanToValue[ "XL" ] = 40;
        romanToValue[ "XC" ] = 90;
        romanToValue[ "CD" ] = 400;
        romanToValue[ "CM" ] = 900;
        
        int arabic = 0;
        for( int i = 0; i < s.length(); ++i ) {
            const int lastElement = s.length() - 1;
            auto it = romanToValue.find( s.substr( i, 2 ) );
            if( it != romanToValue.end() ) {
                arabic += it->second;
                ++i;
                continue;
            }
            it = romanToValue.find( s.substr( i, 1 ) );
            if( it != romanToValue.end() ) {
                arabic += it->second;
            }
        }       
        return arabic;
    }
};
