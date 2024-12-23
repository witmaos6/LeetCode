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
    using Pair = pair<int, int>;
public:
    int minimumOperations(TreeNode* root)
    {
        queue<TreeNode*> BFS;
        BFS.push(root);
        int Total = 0;
        
        while(!BFS.empty())
        {
            const int Range = static_cast<int>(BFS.size());
            vector<Pair> Levels(Range);
            for(int i = 0; i < Range; i++)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();
                
                Levels[i] = {Node->val, i};
                if(Node->left)
                {
                    BFS.push(Node->left);
                }
                if(Node->right)
                {
                    BFS.push(Node->right);
                }
            }
            
            sort(Levels.begin(), Levels.end());
            int Count = 0;
            for(int i = 0; i < Range; i++)
            {
                int OriginIndex = Levels[i].second;
                if(OriginIndex != i)
                {
                    swap(Levels[i], Levels[OriginIndex]);
                    Count++;
                    i--;
                }
            }
            
            Total += Count;
        }
        
        return Total;
    }
};