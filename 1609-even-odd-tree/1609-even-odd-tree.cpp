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
    bool isEvenOddTree(TreeNode* root)
    {
        queue<TreeNode*> BFS;
        BFS.push(root);
        int Index = 0;
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            int Comparison = (Index & 1) ? INT_MAX : INT_MIN;
            
            for(size_t i = 0; i < Range; i++)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();
                
                if(Node->left)
                {
                    BFS.push(Node->left);
                }
                if(Node->right)
                {
                    BFS.push(Node->right);
                }
                
                if(Index & 1)
                {
                    if((Node->val & 1) == 1 || Node->val >= Comparison)
                        return false;
                }
                else
                {
                    if((Node->val & 1) == 0 || Node->val <= Comparison)
                        return false;
                }
                Comparison = Node->val;
            }
            
            Index++;
        }
        return true;
    }
};