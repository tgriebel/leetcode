/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

class Codec {
public:
    
    void tokenize( string s, vector<string>& tokens ) {
        for( int i = 0; i < s.size(); ++i ) {
            if( s[i] == ',' ) {
                s[i] = '\n';
            }
        }
        stringstream ss( s );
        string token;
        while( ss >> token ) {
            tokens.push_back( token );
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        string asString;
        deque<TreeNode*> workQueue;
        workQueue.push_back( root );
        while( !workQueue.empty() ) {
            TreeNode* n = workQueue.front();
            workQueue.pop_front();
            if( n == nullptr ) {
                ss << "null,";
            } else {
                ss << n->val << ",";
                workQueue.push_back( n->left );
                workQueue.push_back( n->right );
            }
        }
        asString = ss.str();
        //cout << "o: " << asString << endl;
        return asString;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if( data.size() == 0 ) {
           return nullptr;
        }
        vector<string> tokens;
        tokenize( data, tokens );
        
        if( tokens[ 0 ] == "null" ) {
            return nullptr;
        }
        
        int val;
        stringstream( tokens[ 0 ] ) >> val;
        
        TreeNode* root = new TreeNode( val );
        
        deque<TreeNode*> parents;
        parents.push_back( root );
        
        int t = 1;
        const int numTokens = tokens.size();
        while( t < numTokens ) {
            const int numParents = parents.size();
            for( int i = 0; i < numParents; ++i ) {
                TreeNode* parent = parents.front();
                parents.pop_front();
                
                TreeNode** children[ 2 ] = { &parent->left, &parent->right };

                for( int childIx = 0; childIx < 2; ++childIx ) {
                    if( ( tokens[ t ] != "null" ) && ( t < numTokens ) ) {
                        stringstream( tokens[ t ] ) >> val;

                        *children[ childIx ] = new TreeNode( val );             
                        parents.push_back( *children[ childIx ] );
                    }
                    ++t;
                }
            }
        }
        return root;
    }
};
