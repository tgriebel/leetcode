class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for( int i = 0; i < 32; ++i ) {
            count += ( n & 0x01 );
            n >>= 1;
        }
        return count;
    }
};
