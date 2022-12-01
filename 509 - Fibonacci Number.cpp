class Solution {
public:
    int fib(int n) {
        if( n <= 0 ) {
            return 0;
        }
        if( n <= 1 ) {
            return 1;
        }

        int fn0 = 0;
        int fn1 = 1;
        for(int i = 2; i <= n; ++i) {
            int next = fn1 + fn0;
            fn0 = fn1;
            fn1 = next;
        }
        return fn1;
    }
};
