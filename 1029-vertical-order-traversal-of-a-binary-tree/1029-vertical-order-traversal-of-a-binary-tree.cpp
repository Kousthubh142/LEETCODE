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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<tuple<TreeNode*,int,int>> q;

        q.push({root,0,0}); 
        while(!q.empty()) {
            auto [node,ver,row]=q.front();
            q.pop();
            nodes[ver][row].insert(node->val);

            if(node->left) q.push({node->left,ver-1,row+1});
            if(node->right) q.push({node->right,ver+1,row+1});
        }

        vector<vector<int>> ans;
        for(auto p:nodes) {
            vector<int> ver;
            for(auto q:p.second) {
                ver.insert(ver.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(ver);
        }
        return ans;
    }
};