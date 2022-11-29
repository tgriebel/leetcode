class Solution {
public:
    double myPow(double x, int n) {
        if( ( n == 0 ) || (x == 1.0) ) {
            return 1.0;
        }
        
        int64_t N = abs(int64_t(n)); 
        
        double y = 1.0;
        while( N > 1 ) {
            if( (N % 2) == 0 ) {
                x = x * x;
                N = N / 2;
            } else {          
                y = x * y;
                x = x * x;
                N = (N - 1) / 2;
            }
        }
        return (n > 0) ? (x * y) : 1.0 / (x * y);
    }
};
