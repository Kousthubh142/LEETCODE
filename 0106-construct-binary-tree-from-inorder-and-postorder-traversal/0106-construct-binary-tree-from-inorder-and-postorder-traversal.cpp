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
    int postor=0;

    TreeNode* helper(vector<int>& postorder, int left , int right) {
        if(left>right) return nullptr;
        int rootval=postorder[postor--];
        TreeNode* root= new TreeNode(rootval);
        int mid= inordered[rootval];

        root->right=helper(postorder, mid+1,right);
        root->left= helper(postorder, left, mid-1);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++) inordered[inorder[i]]=i;
        postor= postorder.size()-1;
        return helper(postorder, 0, postorder.size()-1);
    }
};