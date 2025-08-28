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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> a;
        vector<int> b;

        dfs(p,a);
        dfs(q,b);

        return a==b;
    }

private:
    void dfs(TreeNode* root,vector<int>& ans) {
        if(!root) { 
            ans.push_back(INT_MIN);
            return;
        }

        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
};