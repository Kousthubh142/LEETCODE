/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(!root) return "X,";
       return to_string(root->val) +',' +serialize(root->left) + serialize(root->right);
    }

    TreeNode* helper (queue<string>& q) {
        string val = q.front();
        q.pop();
        if(val=="X") {
            return nullptr;
        }
        TreeNode* node=new TreeNode(stoi(val));
        node->left=helper(q);
        node->right=helper(q);

        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        queue<string> q;

        while (getline(ss, val,',')) {
            q.push(val);
        } 

        return helper(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));