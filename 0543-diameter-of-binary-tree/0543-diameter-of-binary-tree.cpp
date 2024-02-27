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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        GetDiameter(root);
        return Result;
    }
    
private:
    int GetDiameter(TreeNode* Node)
    {
        if(Node == nullptr)
            return 0;
        
        int Left = GetDiameter(Node->left);
        int Right = GetDiameter(Node->right);
        
        Result = max(Result, Left + Right);
        
        return max(Left, Right) + 1;
    }
};