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
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> Result;
        if(root == nullptr)
        {
            return Result;
        }
        
        queue<TreeNode*> BFS;
        BFS.push(root);
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            int MaxValue = INT_MIN;
            
            for(size_t i = 0; i < Range; i++)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();
                
                MaxValue = max(MaxValue, Node->val);
                
                if(Node->left)
                {
                    BFS.push(Node->left);
                }
                if(Node->right)
                {
                    BFS.push(Node->right);
                }
            }
            
            Result.push_back(MaxValue);
        }
        
        return Result;
    }
};