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
    int sumOfLeftLeaves(TreeNode* root)
    {
        return SumOfLeftLeaves(root, false);
    }
private:
    int SumOfLeftLeaves(TreeNode* Node, const bool bIsLeft)
    {
        int LeftValue = 0;
        if(Node)
        {
            if(!Node->left && !Node->right && bIsLeft)
            {
                LeftValue += Node->val;
            }
            LeftValue += SumOfLeftLeaves(Node->left, true);
            LeftValue += SumOfLeftLeaves(Node->right, false);
        }       
        return LeftValue;
    }
};