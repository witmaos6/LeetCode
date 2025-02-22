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
    int N = 0;
    const char Dash = '-';
    int Index = 0;
public:
    TreeNode* recoverFromPreorder(string traversal)
    {
        N = static_cast<int>(traversal.size());
        return recoverFromPreorder(traversal, 0);
    }
private:
    TreeNode* recoverFromPreorder(string& Traversal, int Depth)
    {
        if(Index >= N)
            return nullptr;

        int D = 0;
        while(Traversal[Index] == Dash)
        {
            D++;
            Index++;
        }

        if(D < Depth)
        {
            Index -= D;
            return nullptr;
        }

        int X = 0;
        while(isdigit(Traversal[Index]))
        {
            X = X * 10 + Traversal[Index] - '0';
            Index++;
        }

        TreeNode* Node = new TreeNode(X);
        Node->left = recoverFromPreorder(Traversal, Depth + 1);
        Node->right = recoverFromPreorder(Traversal, Depth + 1);

        return Node;
    }
};