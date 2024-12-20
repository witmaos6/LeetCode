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
            vector<TreeNode*> Levels;
            if((Level & 1) == 1)
            {
                Levels.reserve(Range * 2);
            }
            
            for(size_t i = 0; i < Range; i++)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();

                if(Node->left)
                {
                    BFS.push(Node->left);
                    BFS.push(Node->right);
                }
                
                if((Level & 1) == 1)
                {
                    Levels.push_back(Node);
                }
            }
            
            if(Levels.size() > 0)
            {
                int Right = static_cast<int>(Levels.size()) - 1;
                int Left = 0;
                
                while(Left < Right)
                {
                    swap(Levels[Left]->val, Levels[Right]->val);
                    Left++;
                    Right--;
                }
            }
            
            Level++;
        }
        
        return root;
    }
};