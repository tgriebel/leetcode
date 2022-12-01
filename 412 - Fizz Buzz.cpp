class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        answer.resize( n );
        
        char buffer[ 16 ];
        
        for( int i = 1; i <= n; ++i ) {
            const bool isMultFive = ( i % 5 ) == 0;
            const bool isMultThree = ( i % 3 ) == 0;

            if( isMultFive && isMultThree ) {
                answer[ i - 1 ] = "FizzBuzz";
            } else if( isMultFive ) {
                answer[ i - 1 ] = "Buzz";
            } else if ( isMultThree ) {
                answer[ i - 1 ] = "Fizz";
            } else {
                sprintf( buffer, "%d", i );
                answer[ i - 1 ] = string( buffer );
            }
        }
        return answer;
    }
};
