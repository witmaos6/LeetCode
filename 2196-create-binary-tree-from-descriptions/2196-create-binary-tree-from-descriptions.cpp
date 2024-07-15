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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        unordered_map<int, TreeNode*> Table;
        unordered_set<int> Children;
        const int N = static_cast<int>(descriptions.size());
        for(int i = 0; i < N; i++)
        {
            const int Parent = descriptions[i][0];
            const int Child = descriptions[i][1];
            const int IsLeft = descriptions[i][2];
            
            if(Table.find(Parent) == Table.end())
            {
                Table[Parent] = new TreeNode(Parent);   
            }
            if(Table.find(Child) == Table.end())
            {
                Table[Child] = new TreeNode(Child);
            }
            if(IsLeft == 1)
            {
                Table[Parent]->left = Table[Child];
            }
            else
            {
                Table[Parent]->right = Table[Child];
            }
            
            Children.insert(Child);
        }
        
        for(auto& [Value, Node] : Table)
        {
            if(Children.find(Value) == Children.end())
            {
                return Node;
            }
        }
        
        return Table.begin()->second;
    }
};