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
    vector<int> findMode(TreeNode* root)
    {
        unordered_map<int, int> Table;
        queue<TreeNode*> BFS;
        BFS.push(root);
        int MostFreq = 0;
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            
            for(size_t i = 0; i < Range; i++)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();
                
                Table[Node->val]++;
                MostFreq = max(MostFreq, Table[Node->val]);
                
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
        
        vector<int> Result;
        for(auto& [Value, Freq] : Table)
        {
            if(MostFreq == Freq)
            {
                Result.push_back(Value);
            }
        }
        
        return Result;
    }
};