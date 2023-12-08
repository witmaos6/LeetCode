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
    string tree2str(TreeNode* root)
    {
        string TreeToString = GetSubtree(root);
        
        return TreeToString;
    }
    
private:
    string GetSubtree(TreeNode* Root)
    {
        if(!Root)
        {
            return "";
        }
        string Subtree = to_string(Root->val);
        
        string LeftTree;
        string RightTree;
        
        if(Root->left || Root->right)
        {
            LeftTree = '(' + GetSubtree(Root->left) + ')';
        }
        if(Root->right)
        {
            RightTree = '(' + GetSubtree(Root->right) + ')';
        }
        
        return Subtree + LeftTree + RightTree;
    }
};