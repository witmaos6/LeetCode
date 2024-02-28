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
    int findBottomLeftValue(TreeNode* root)
    {
        queue<TreeNode*> BFS;
        BFS.push(root);
        int LeftMost = 0;
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            LeftMost = BFS.front()->val;
            
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
            }
        }
        
        return LeftMost;
    }
};