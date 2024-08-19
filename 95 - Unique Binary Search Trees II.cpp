/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end) {
        
        vector<TreeNode*> list;
        if( start > end ) {
            list.push_back( nullptr );
            return list; 
        }

        vector<TreeNode*> leftList;
        vector<TreeNode*> rightList;

        for( int root = start; root <= end; ++root ) {
            leftList = generateTrees( start, root - 1 );
            rightList = generateTrees( root + 1, end );

            for( int l = 0; l < leftList.size(); ++l ) {
                for( int r = 0; r < rightList.size(); ++r ) {
                    list.push_back( new TreeNode( root, leftList[ l ], rightList[ r ] ) );
                }
            }
        }
        return list;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTrees( 1, n );
    }
};
