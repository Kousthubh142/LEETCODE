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
    unordered_map<int,int> inordered;
    int inor=0;

    TreeNode* helper(vector<int>& preorder, int left, int right){
        if(left>right) return nullptr;

        int rootval=preorder[inor++];
        TreeNode* root= new TreeNode(rootval);

        int mid = inordered[rootval];

        root->left= helper(preorder,left,mid-1);
        root->right=helper(preorder, mid+1, right);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++) inordered[inorder[i]]=i;
        return helper(preorder, 0, preorder.size()-1);
    }
};