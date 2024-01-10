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
    int amountOfTime(TreeNode* root, int start)
    {
        if(!root->left && !root->right)
        {
            return 0;
        }
        
        int StartDepth = FindStartDepth(root, start, 0);
     
        DFS(root, StartDepth, start);
        
        return Result;
    }
    
private:
    int FindStartDepth(TreeNode* Root, const int Start, int Count)
    {
        if(!Root)
            return 0;
        
        if(Start == Root->val)
            return Count;
       
        int LeftDepth = FindStartDepth(Root->left, Start, Count + 1);
        int RightDepth = FindStartDepth(Root->right, Start, Count + 1);
        return LeftDepth + RightDepth;
    }
    
    bool DFS(TreeNode* Root, const int Depth, const int Start)
    {
        if(!Root)
            return false;
        
        if(Root->val == Start)
        {
            Result = max(Result, FindMaxTime(Root) - 1);
            return true;
        }
        
        bool Left = DFS(Root->left, Depth - 1, Start);
        bool Right = DFS(Root->right, Depth - 1, Start);
        
        if(Left)
        {
            Result = max(Result, FindMaxTime(Root->right) + Depth);
        }
        if(Right)
        {
            Result = max(Result, FindMaxTime(Root->left) + Depth);
        }
        return Left || Right;
    }
    
    int FindMaxTime(TreeNode* Root)
    {
        if(!Root)
            return 0;
        
        return max(FindMaxTime(Root->left), FindMaxTime(Root->right)) + 1;
    }
};