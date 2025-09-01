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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> ans;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()) {
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++) {
                TreeNode* cur=q.front();
                q.pop();

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);

                level.push_back(cur->val);
            }
            double l=0;
            for(int num:level) {
                l+=(double)num;
            }
            l=l/(level.size());
            ans.push_back(l);
        }
        return ans;
    }
};