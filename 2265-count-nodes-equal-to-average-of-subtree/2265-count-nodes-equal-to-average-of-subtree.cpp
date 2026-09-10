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
    using Pair = pair<int, int>; // NumberOfNode, Sum
    int Result = 0;
public:
    int averageOfSubtree(TreeNode* root)
    {
        DFS(root);

        return Result;        
    }

private:
    Pair DFS(TreeNode* Node)
    {
        if(Node == nullptr)
            return {0, 0};
        
        Pair LeftTree = DFS(Node->left);
        Pair RightTree = DFS(Node->right);

        int Count = LeftTree.first + RightTree.first + 1;
        int Sum = LeftTree.second + RightTree.second + Node->val;

        if(Node->val == Sum / Count)
        {
            Result++;
        }

        return {Count, Sum};
    }
};