// Level-order traversal

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        vector<vector<TreeNode *>> v;
        queue<pair<int, TreeNode *>> q;
        pair<int, TreeNode *> p;

        q.push(make_pair(0, root));
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            while (v.size() <= p.first)
            {
                v.push_back(vector<TreeNode *>());
            }
            v[p.first].push_back(p.second);
            if (p.second == NULL)
            {
                continue;
            }
            q.push(make_pair(p.first + 1, (p.second)->left));
            q.push(make_pair(p.first + 1, (p.second)->right));
        }
        int n = v.size();
        int i;
        for (i = 0; i < n; i++)
        {
            if (!isSymmetricArray(v[i]))
            {
                break;
            }
        }
        v.clear();
        return i == n;
    }
    bool isSymmetricArray(vector<TreeNode *> &v)
    {
        int n = v.size();
        int i;
        for (i = 0; i < n - i - 1; i++)
        {
            if (v[i] == NULL || v[n - i - 1] == NULL)
            {
                if (v[i] != v[n - i - 1])
                {
                    return false;
                }
                continue;
            }
            if (v[i]->val != v[n - i - 1]->val)
            {
                return false;
            }
        }
        return true;
    }
};