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
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        int Left = Depth(root->left);
        int Right = Depth(root->right);
        if(Left == Right)
        {
            return root;
        }
        else if(Left > Right)
        {
            root = root->left;
        }
        else if(Left < Right)
        {
            root = root->right;
        }
        return lcaDeepestLeaves(root);
    }

    int Depth(TreeNode* Root)
    {
        if(Root == nullptr)
            return 0;

        int L = Depth(Root->left);
        int R = Depth(Root->right);
        return max(L, R) + 1;
    }
};