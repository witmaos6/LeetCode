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
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        queue<TreeNode*> BFS;
        BFS.push(root);
        
        int Result = 0;
        
        while(!BFS.empty())
        {
            TreeNode* Node = BFS.front();
            BFS.pop();
            
            if(Node->val >= low && Node->val <= high)
            {
                Result += Node->val;
            }
            if(Node->left)
            {
                BFS.push(Node->left);
            }
            if(Node->right)
            {
                BFS.push(Node->right);
            }
        }
        
        return Result;
    }
};
