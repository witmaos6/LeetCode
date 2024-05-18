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
    using StNode = tuple<TreeNode*, TreeNode*, bool>;
public:
    int distributeCoins(TreeNode* root)
    {
        stack<StNode> St;
        St.push({root, nullptr, false});
        int Moves = 0;
        
        while(!St.empty())
        {
            auto[Node, Parent, Visited] = St.top();
            St.pop();
            
            if(!Visited)
            {
                St.emplace(Node, Parent, true);
                
                if(Node->left)
                {
                    St.emplace(Node->left, Node, false);
                }
                if(Node->right)
                {
                    St.emplace(Node->right, Node, false);
                }
            }
            else
            {
                int Coin = Node->val - 1;
                if(Parent)
                {
                    Parent->val += Coin;
                }
                Moves += abs(Coin);
            }
            
        }
        
        return Moves;
    }
};