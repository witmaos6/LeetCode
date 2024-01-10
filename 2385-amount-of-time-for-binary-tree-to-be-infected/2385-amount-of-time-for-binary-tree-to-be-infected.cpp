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
    unordered_map<int, vector<int>> Graph;
public:
    int amountOfTime(TreeNode* root, int start)
    {
        ConstructGraph(root);
        
        unordered_set<int> Visited;
        
        queue<int> BFS;
        BFS.push(start);
        
        int Result = -1;
        
        while(!BFS.empty())
        {
            Result++;
            
            int Range = static_cast<int>(BFS.size());
            for(int i = 0; i < Range; i++)
            {
                int Node = BFS.front();
                BFS.pop();
                Visited.insert(Node);
                
                for(int AdjNode : Graph[Node])
                {
                    if(Visited.find(AdjNode) == Visited.end())
                    {
                        BFS.push(AdjNode);
                    }
                }
            }
        }
        
        return Result;
    }
    
private:
    void ConstructGraph(TreeNode* Root)
    {
        if(!Root)
            return;
        
        if(Root->left)
        {
            Graph[Root->val].push_back(Root->left->val);
            Graph[Root->left->val].push_back(Root->val);
        }
        
        if(Root->right)
        {
            Graph[Root->val].push_back(Root->right->val);
            Graph[Root->right->val].push_back(Root->val);
        }
        
        ConstructGraph(Root->left);
        ConstructGraph(Root->right);
    }
};