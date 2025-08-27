/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        if (root == NULL) {
            return post;
        }
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* last = NULL;

        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top();
                if (temp->right != NULL && last != temp->right) {
                    curr = temp->right;
                } else {
                    post.push_back(temp->val);
                    last = temp;
                    st.pop();
                }
            }
        }
        return post;
    }
};