/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        res.clear();
        if (root == NULL) return res;
        while (!q.empty()) {
            int rowSize = q.size();
            int max = 0;
            for (int i = 0; i < rowSize; i++) {
                TreeNode* t = q.front();
                q.pop();
                if (t == NULL) continue;
                if (i == 0) max = t->val;
                max = t->val > max ? t->val : max;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right); 
            }
            res.push_back(max);
        }
        return res;
    }
};