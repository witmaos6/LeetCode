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
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        queue<TreeNode*> BFS;
        BFS.push(root);
        int Level = 0;
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            queue<TreeNode*> LevelQueue;
            stack<int> Reverse;
            
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
                
                if((Level & 1) == 1)
                {
                    LevelQueue.push(Node);
                    Reverse.push(Node->val);
                }
            }
            
            while(!LevelQueue.empty())
            {
                TreeNode* Node = LevelQueue.front();
                LevelQueue.pop();
                
                int Value = Reverse.top();
                Reverse.pop();
                
                Node->val = Value;
            }
            Level++;
        }
        
        return root;
    }
};