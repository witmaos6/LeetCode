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
    vector<TreeNode*> Rebuild;
public:
    TreeNode* balanceBST(TreeNode* root)
    {
        Inorder(root);
        
        return SetRebuild(0, Rebuild.size() - 1);
    }
    
private:
    void Inorder(TreeNode* Node)
    {
        if(Node)
        {
            Inorder(Node->left);
            Rebuild.push_back(Node);
            Inorder(Node->right);
        }
    }
    
    TreeNode* SetRebuild(int Left, int Right)
    {
        if(Left > Right)
            return nullptr;
        
        int Mid = (Left + Right) / 2;
                
        Rebuild[Mid]->left = SetRebuild(Left, Mid - 1);
        Rebuild[Mid]->right = SetRebuild(Mid + 1, Right);
        
        return Rebuild[Mid];
    }
};