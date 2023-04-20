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
    typedef pair<TreeNode*, long long> Node;
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        long long MaxWidth = 0;
        queue<Node> BFS;
        BFS.push({root, 1});
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            
            long long BeginPoint = BFS.front().second;
            long long EndPoint = BFS.back().second;

            MaxWidth = max(MaxWidth, EndPoint - BeginPoint + 1);
            
            for(size_t i = 0; i < Range; i++)
            {
                TreeNode* CurrNode = BFS.front().first;
                long long CurrIndex = BFS.front().second - BeginPoint;
                BFS.pop();
                
                if(CurrNode->left)
                {
                    long long NextIndex = 2 * CurrIndex;
                    BFS.push({CurrNode->left, NextIndex});
                }
                if(CurrNode->right)
                {
                    long long NextIndex = 2 * CurrIndex + 1;
                    BFS.push({CurrNode->right, NextIndex});
                }
            }
        
        }
        
        return static_cast<int>(MaxWidth);
    }
};