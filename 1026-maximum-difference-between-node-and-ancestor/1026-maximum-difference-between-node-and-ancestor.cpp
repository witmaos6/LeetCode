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
    int Result = 0;
public:
    int maxAncestorDiff(TreeNode* root)
    {
        DFS(root, INT_MAX, INT_MIN);
        
        return Result;
    }

private:
    void DFS(TreeNode* Node, int MinValue, int MaxValue)
    {
        if(!Node)
        {
            return;
        }

        MinValue = min(MinValue, Node->val);
        MaxValue = max(MaxValue, Node->val);

        Result = max(Result, MaxValue - MinValue);

        if(Node->left)
        {
            DFS(Node->left, MinValue, MaxValue);
        }
        if(Node->right)
        {
            DFS(Node->right, MinValue, MaxValue);
        }
    }
};