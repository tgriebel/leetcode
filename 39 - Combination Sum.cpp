class Solution {
public:
    void combinationSum(vector<int>& candidates, int startIx, int target, vector<vector<int>>& solutions, vector<int>& currentSelection ) {
        for( int i = startIx; i < candidates.size(); ++i  ) {
            int choice = candidates[ i ];

            if( ( target - choice ) < 0 ) {
                continue;
            }

            vector<int> list = currentSelection;
            list.push_back( choice );

            if( ( target - choice ) == 0) {
                solutions.push_back( list );
                return;
            }

            if( ( target - choice ) > 0 ) {
                combinationSum( candidates, i, target - choice, solutions, list );
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solutions;
        vector<int> currentSelection;
        set<int> listSizes;

        sort( candidates.begin(), candidates.end() );

        combinationSum( candidates, 0, target, solutions, currentSelection );

        return solutions;
    }
};
