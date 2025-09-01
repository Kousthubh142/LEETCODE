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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);

        TreeNode* cur=root;

        while(cur) {
            if(val<cur->val && cur->left) cur=cur->left;
            else if(val<cur->val) {
                TreeNode* node=new TreeNode(val);
                cur->left=node;
                return root;
            }
            else if(val>cur->val && cur->right) cur=cur->right;
            else {
                TreeNode* node=new TreeNode(val);
                cur->right=node;
                return root;
            }
        }

        return root;
    }
};