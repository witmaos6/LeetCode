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
    int distributeCoins(TreeNode* root)
    {
        return distributeCoins(root, nullptr);
    }
    
private:
    int distributeCoins(TreeNode* Node, TreeNode* ParentNode)
    {
        if(Node == nullptr)
            return 0;
        
        int Moves = distributeCoins(Node->left, Node) + distributeCoins(Node->right, Node);
        
        int Coin = Node->val - 1;
        if(ParentNode)
        {
            ParentNode->val += Coin;           
        }
        
        Moves += abs(Coin);
        return Moves;
    }
    
};