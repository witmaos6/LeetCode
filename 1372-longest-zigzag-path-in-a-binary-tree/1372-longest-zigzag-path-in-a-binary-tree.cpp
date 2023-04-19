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
    const char Left = 'L';
    const char Right = 'R';
public:
    int longestZigZag(TreeNode* root)
    {
        if(root->right)
        {
            Search(root->right, Right, 1);
        }
        if(root->left)
        {
            Search(root->left, Left, 1);
        }
        
        return Result;
    }    
private:
    void Search(TreeNode* root, char Prev, int Path)
    {
        if(root->right)
        {
            if(Prev == Left)
            {
                Search(root->right, Right, Path + 1);
            }
            else
            {
                Search(root->right, Right, 1);
            }
        }
        if(root->left)
        {
            if(Prev == Right)
            {
                Search(root->left, Left, Path + 1);
            }
            else
            {
                Search(root->left, Left, 1);
            }
        }
        Result = max(Result, Path);
    }
};