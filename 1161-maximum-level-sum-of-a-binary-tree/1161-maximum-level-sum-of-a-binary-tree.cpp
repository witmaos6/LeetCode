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
    int maxLevelSum(TreeNode* root)
    {
        queue<TreeNode*> BFS;
        BFS.push(root);
        
        int MaxLevel = 1;
        int CurrLevel = 1;
        int MaxSum = root->val;
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            int Sum = 0;
            
            for(size_t i = 0; i < Range; i++)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();
                
                Sum += Node->val;
                
                if(Node->left)
                {
                    BFS.push(Node->left);
                }
                if(Node->right)
                {
                    BFS.push(Node->right);
                }
            }
            if(MaxSum < Sum)
            {
                MaxSum = Sum;
                MaxLevel = CurrLevel;
            }
            CurrLevel++;
        }
        
        return MaxLevel;
    }
};