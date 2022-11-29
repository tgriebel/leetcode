class Solution {
public:
    int reverse(int x) {
        const int minChk = ( INT_MIN / 10 );
        const int maxChk = ( INT_MAX / 10 );
        int source = x;
        int reversed = 0;
        while( source != 0 ) {
            const int digit = source % 10;
            source /= 10;
                     
            if( ( reversed > maxChk ) || ( ( reversed == maxChk ) && ( digit > 7 ) ) ) {
                return 0;
            }
            if( ( reversed < minChk ) || ( ( reversed == minChk ) && ( digit < -8 ) ) ) {
                return 0;
            }
                
            reversed *= 10;
            reversed += digit;
        }
        return reversed;
    }
};
