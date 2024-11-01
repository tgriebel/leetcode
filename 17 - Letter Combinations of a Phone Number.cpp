class Solution {
public:
    static constexpr string map[12] = {
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
        "+",
        " ",
        "#"
    };

    void letterCombindations( string& digits, int offset, string combo, vector<string>& combinations ) {
        if( offset >= digits.size() ) {
            combinations.push_back( combo );
            return;
        }   
        int lookupIndex = digits[ offset ] - '1';
        string letters = map[ lookupIndex ];
        for( int i = 0; i < letters.size(); ++i ) {
            letterCombindations( digits, offset + 1, combo + letters[ i ], combinations );
        }
    }

    vector<string> letterCombinations( string digits ) {    
        vector<string> combinations;
        if( digits.size() == 0 ) {
            return combinations;
        } 
        letterCombindations( digits, 0, "", combinations );
        return combinations;
    }
};
