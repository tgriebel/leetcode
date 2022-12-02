class Solution {
public:
    int countOdds(int low, int high) {
        high = ( high - 1 ) | 0x01;
        low = low | 0x01;
        return ( ( high - low ) / 2 ) + 1;
    }
};
