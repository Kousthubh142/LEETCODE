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
    void flatten(TreeNode* root) {
        if(!root) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* left=root->left;
        TreeNode* right=root->right;

        if(left) {
            root->right=left;
            root->left=nullptr;

            TreeNode* temp=root->right;
            while(temp->right) {
                temp=temp->right;
            }

            temp->right=right;
        }
    }
};