/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void preorderTraversal( const Node* node, vector<int>& list ) {
        list.push_back( node->val );
        for( int i = 0; i < node->children.size(); ++i ) {
            preorderTraversal( node->children[i], list );
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> list;
        if( root == nullptr ) {
            return list;
        }
        preorderTraversal( root, list );
        return list;
    }
};
