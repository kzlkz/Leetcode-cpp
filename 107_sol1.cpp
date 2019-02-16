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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
    }
    private:
    vector<vector<int>> res;
    void levelOrder(TreeNode* root, int level) {
        if (res.size() <= level) {
            res.push_back(vector<int>());
        }
    }
};