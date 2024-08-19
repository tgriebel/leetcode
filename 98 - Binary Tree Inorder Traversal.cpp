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
private:
    void inorder( TreeNode* node, std::vector<int>& orderedList ) {
        if( node->left != nullptr ) {
            inorder( node->left, orderedList );
        }
        orderedList.push_back( node->val );
        if( node->right != nullptr ) {
            inorder( node->right, orderedList );
        }
    }

    static constexpr bool recursive = false;
public:


    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> orderedList;

        if( root == nullptr ) {
            return orderedList;
        }
        inorder( root, orderedList );

        return orderedList;
    }
};
