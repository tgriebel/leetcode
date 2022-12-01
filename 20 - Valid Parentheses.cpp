class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for( int i = 0; i < s.size(); ++i ) {
            const char c = s[ i ];
            if( ( c == '(' ) || ( c == '{' ) || ( c == '[' ) ) {
                stack.push_back( c );  
            } else if( c == ')' ) {
                if( stack.empty() || stack.back() != '(' ) {
                    return false;
                }
                stack.pop_back();
            } else if( c == '}' ) {
                if( stack.empty() || stack.back() != '{' ) {
                    return false;
                }
                stack.pop_back();
            } else if( c == ']' ) {
                if( stack.empty() || stack.back() != '[' ) {
                    return false;
                }
                stack.pop_back();
            }
        }
        return ( stack.empty() );
    }
};
