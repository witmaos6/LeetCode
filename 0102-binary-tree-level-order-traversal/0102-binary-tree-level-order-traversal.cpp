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
    vector<vector<int>> LevelOrder;
    
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if(!root)
            return LevelOrder;
        
        queue<TreeNode*> BFS;
        BFS.push(root);
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            vector<int> Level;
            
            while(Range--)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();
                
                Level.push_back(Node->val);
                
                if(Node->left)
                {
                    BFS.push(Node->left);
                }
                if(Node->right)
                {
                    BFS.push(Node->right);
                }
            }
            
            LevelOrder.push_back(Level);
        }
        
        return LevelOrder;
    }
};