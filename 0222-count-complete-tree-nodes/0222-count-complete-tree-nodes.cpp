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
    int leftheight(TreeNode* root) {
        if(!root) return 0;

        int h=0;
        while(root) {
            h++;
            root=root->left;
        }

        return h;
    }

    int rightheight(TreeNode* root) {
        if(!root) return 0;

        int h=0;
        while(root) {
            h++;
            root=root->right;
        }
        return h;
    }

public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh=leftheight(root);
        int rh=rightheight(root);

        if(lh==rh) return ((1<<lh) -1);

        return 1+ countNodes(root->left) +countNodes(root->right);

    }
};