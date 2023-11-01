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
    int PrevValue = INT_MIN;
    int MaxCount = 0;
    int Count = 0;
    vector<int> Result;
public:
    vector<int> findMode(TreeNode* root)
    {
        Inorder(root);
        
        return Result;
    }
    
private:
    void Inorder(TreeNode* root)
    {
        if(root == nullptr)
            return;
        
        Inorder(root->left);
        
        if(root->val == PrevValue)
        {
            Count++;
        }
        else
        {
            Count = 1;
        }
        
        if(Count > MaxCount)
        {
            MaxCount = Count;
            Result.clear();
            
            Result.push_back(root->val);
        }
        else if(Count == MaxCount)
        {
            Result.push_back(root->val);
        }
        
        PrevValue = root->val;
        
        Inorder(root->right);
    }
};