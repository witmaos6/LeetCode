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
    bool evaluateTree(TreeNode* root)
    {
        if(root == nullptr)
            return false;
        
        if(IsLeafNode(root))
        {
            return (root->val == 1) ? true : false;
        }

        bool LeftNode = evaluateTree(root->left);
        bool RightNode = evaluateTree(root->right);

        if(root->val == 2)
        {
            return LeftNode || RightNode;
        }
        else if(root->val == 3)
        {
            return LeftNode && RightNode;
        }
        
        return true;
    }
private:
    bool IsLeafNode(TreeNode* Node)
    {
        if(Node->right == nullptr && Node->left == nullptr)
            return true;
        
        return false;
    }
};