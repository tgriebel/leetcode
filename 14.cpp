class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int maxStrLength = 200;
        const int numStrings = strs.size();
        if( numStrings == 1 ) {
            return strs[0];
        }
        
        int minIndex = maxStrLength + 1;
        for(int i = 0; i < numStrings; ++i) {
            const string& str0 = strs[i];
            const int strLength0 = str0.size();
            for(int j = i + 1; j < numStrings; ++j) {
                int m = 0;
                const string& str1 = strs[j];
                const int strLength1 = str1.size();
                while( ( m < strLength0 ) && ( m < strLength1 ) ) {
                    const string& str1 = strs[j];
                    if( str0[m] == str1[m] ) {
                        ++m;
                    } else { 
                        break;
                    }
                }
                minIndex = min( minIndex, m );
            }
        }
        if( minIndex > maxStrLength ) {
            return "";
        } else {
            return strs[0].substr(0, minIndex);
        }
    }
};
