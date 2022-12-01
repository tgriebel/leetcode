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
    TreeNode* invertTree(TreeNode* root) {
        if( root == nullptr ) {
            return nullptr;
        }
        
        deque<TreeNode*> workQueue;
        workQueue.push_back( root );
        while( !workQueue.empty() ) {
            TreeNode* n = workQueue.front();
            workQueue.pop_front();
            
            TreeNode* temp = n->left;
            n->left = n->right;
            n->right = temp;
            
            if( n->left != nullptr ) {
                workQueue.push_back( n->left );
            }
            if( n->right != nullptr ) {
                workQueue.push_back( n->right );
            }
        }
        return root;
    }
};
