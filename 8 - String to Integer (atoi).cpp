class Solution {
private:
    bool IsNumber( const char c ) {
        return ( c >= '0' ) && ( c <= '9' );       
    }
    bool IsSign( const char c ) {
        return ( c == '-' ) || ( c == '+' );
    }
    bool IsWhitespace( const char c ) {
        return ( c == ' ' );
    }
    bool IsZero( const char c ) {
        return ( c == '0' );
    }
    bool IsText( const char c ) {
            return ( c == ' ' ) ||
                    ( c == '.' ) ||
                    ( ( tolower( c ) >= 'a' ) && ( tolower( c ) <= 'z' ) );
    }
    int Sign( const char c ) {
        return ( c == '-' ) ? -1 : 1;
    }
public:
    int myAtoi(string s) {
        const int minInt = 0x80000000;
        const int maxInt = 0x7FFFFFFF;
        
        int64_t total = 0;
        int64_t place = 1; // can store large ints
        int i = 0;
        
        while( IsWhitespace( s[i] ) ) {
            ++i;
        }
        
        int sign = 1;
        if( IsSign( s[i] ) ) {
            sign = Sign( s[i] );
            ++i;
        }
        
        while( IsZero( s[i] ) ) {
            ++i;
        }
        
        int j = i;
        for( ; j < s.size(); ++j ) {
            if( IsNumber( s[j] ) == false ) {
                break;
            }
        }
        if( ( j - i ) > 10 ) {
            return ( sign == 1 ) ? maxInt : minInt;
        }
        for( int k = ( j - 1 ); k >= i; --k ) {
            const int64_t digit = static_cast< int >( s[k] - '0' );
            total += place * digit;
            place *= 10;
        }
        total *= sign;
        total = ( total > maxInt ) ? maxInt : total;
        total = ( total < minInt ) ? minInt : total;
        return static_cast< int >( total );
    }
};
