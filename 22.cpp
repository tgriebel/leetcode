class Solution {
public:
    void generateParenthesis( vector<string>& list, string prefix, int left, int right ) {
        if( ( left == 0 ) && ( right == 0 ) ) {
            list.push_back( prefix );
            return;
        }
        if( left > 0 ) {
            generateParenthesis( list, prefix + "(", left - 1, right + 1 );
        }
        if( right > 0 ) {
            generateParenthesis( list, prefix + ")", left, right - 1 );
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> list;
        list.reserve(64);
        if( n <= 0 ) {
            return list;
        }
        generateParenthesis( list, "", n, 0 );
        return list;
    }
};
