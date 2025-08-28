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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxval=INT_MIN;

        maxi(root,maxval);
        return maxval;
    }
private:
    int maxi(TreeNode* root, int& maxval) {
        if(!root) return 0;

        int lv=max(0,maxi(root->left,maxval));
        int rv=max(0,maxi(root->right,maxval));

        maxval=max(maxval,root->val+lv+rv);

        return root->val + max(lv,rv);
    }
};