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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> Result;
        stack<TreeNode*> St;

        TreeNode* Curr = root;
        while(Curr || !St.empty())
        {
            while(Curr)
            {
                St.push(Curr);
                Curr = Curr->left;
            }

            Curr = St.top();
            St.pop();
            Result.push_back(Curr->val);
            Curr = Curr->right;
        }
        return Result;
    }
};