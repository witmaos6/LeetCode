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
    int CurrSum = 0;
public:
    TreeNode* bstToGst(TreeNode* root)
    {
        if(root == nullptr)
            return nullptr;
        
        if(root->right)
        {
            root->right = bstToGst(root->right);
        }
        CurrSum += root->val;
        root->val = CurrSum;
        
        if(root->left)
        {
            root->left = bstToGst(root->left);
        }
        return root;
    }
};