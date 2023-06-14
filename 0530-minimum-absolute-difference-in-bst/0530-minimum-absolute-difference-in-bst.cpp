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
class Solution 
{
    int MinDiffer = INT_MAX;
    int Pre = -1;
public:
    int getMinimumDifference(TreeNode* root)
    {
        Inorder(root);

        return MinDiffer;
    }
    
private:
    void Inorder(TreeNode* Root)
    {
        if(!Root)
            return;
        
        Inorder(Root->left);
        
        if(Pre != -1)
        {
            int Temp = abs(Root->val - Pre);
            MinDiffer = min(MinDiffer, Temp);
        }
        Pre = Root->val;
        
        Inorder(Root->right);
    }
};