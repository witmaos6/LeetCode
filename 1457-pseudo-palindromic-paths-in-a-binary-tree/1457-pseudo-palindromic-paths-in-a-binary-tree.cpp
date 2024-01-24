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
    int pseudoPalindromicPaths (TreeNode* root)
    {
        int Count = 0;
        
        stack<pair<TreeNode*, int>> DFS;
        DFS.push({root, 0});
        
        while(!DFS.empty())
        {
            auto [Node, Path] = DFS.top();
            DFS.pop();

            if (Node) 
            {
                
                Path = Path ^ (1 << Node->val);
                
                if (Node->left == nullptr && Node->right == nullptr)
                {
                    if ((Path & (Path - 1)) == 0)
                    {
                        ++Count;
                    }
                }
                else
                {
                    DFS.push({Node->right, Path});
                    DFS.push({Node->left, Path});
                }
            }
        }
        
        return Count;
    }
};