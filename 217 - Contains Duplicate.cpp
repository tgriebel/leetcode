class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for( int i = 0; i < nums.size(); ++i ) {
            auto it = m.find( nums[ i ] );
            if( it != m.end() ) {
                return true;
            }
            m[ nums[ i ] ] = 1;
        }
        return false;
    }
};
