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
    int sumRootToLeaf(TreeNode* root)
    {
        return DFS(root, 0);
    }

private:
    int DFS(TreeNode* Root, int Curr)
    {
        if(!Root)
            return 0;

        Curr = Curr * 2 + Root->val;

        if(!Root->left && !Root->right)
        {
            return Curr;
        }

        return DFS(Root->left, Curr) + DFS(Root->right, Curr);
    }
};