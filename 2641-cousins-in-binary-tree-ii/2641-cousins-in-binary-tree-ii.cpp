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
    vector<int> LevelSums;
public:
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        LevelSums.resize(1, 0);
        ChildSum(root, 0);
        
        CousinsSum(root, nullptr, 0);
        
        return root;
    }
    
private:
    void ChildSum(TreeNode* Root, const int Level)
    {
        if(Root == nullptr)
            return;
        
        int Sum = 0;
        if(Root->left)
        {
            Sum += Root->left->val;
        }
        if(Root->right)
        {
            Sum += Root->right->val;
        }
        Root->val = Sum;
        
        if(LevelSums.size() <= Level)
        {
            LevelSums.resize(Level + 1);
        }
        LevelSums[Level] += Sum;
        
        ChildSum(Root->left, Level + 1);
        ChildSum(Root->right, Level + 1);
    }
    
    void CousinsSum(TreeNode* Root, TreeNode* Parent, const int Level)
    {
        if(Root == nullptr)
            return;
        
        CousinsSum(Root->left, Root, Level + 1);
        CousinsSum(Root->right, Root, Level + 1);
        
        if(Parent)
        {
            Root->val = LevelSums[Level - 1] - Parent->val;
        }
        else
        {
            Root->val = 0;
        }
    }
};