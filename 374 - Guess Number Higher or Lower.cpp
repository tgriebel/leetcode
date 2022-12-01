/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        int num = (hi - lo) / 2 + lo;
        int answer = guess(num);
        while(answer != 0) {
            if( answer <= -1 ) {
                hi = num - 1;
            } else if( answer >= 1 ) {
                lo = num + 1;
            }
            num = (hi - lo) / 2 + lo;
            answer = guess(num);
        }
        return num;
    }
};
