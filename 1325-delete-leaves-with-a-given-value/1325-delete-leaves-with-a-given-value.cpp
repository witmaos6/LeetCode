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
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        root = RemoveLeafNodes(root, target);
        
        return root;
    }
private:
    TreeNode* RemoveLeafNodes(TreeNode* Node, const int Target)
    {
        if(Node && Node->left == nullptr && Node->right == nullptr)
        {
            if(Node->val == Target)
                return nullptr;
            
            return Node;
        }
        
        if(Node->left)
        {
            Node->left = RemoveLeafNodes(Node->left, Target);
        }
        if(Node->right)
        {
            Node->right = RemoveLeafNodes(Node->right, Target);
        }
        
        if(Node->left == nullptr && Node->right == nullptr && Node->val == Target)
        {
            return nullptr;
        }
        return Node;
    }
};