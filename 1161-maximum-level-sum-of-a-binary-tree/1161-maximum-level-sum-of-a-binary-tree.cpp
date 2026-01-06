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
    int maxLevelSum(TreeNode* root)
    {
        if(root == nullptr)
            return 0;

        queue<TreeNode*> BFS;
        BFS.push(root);
        int Max = INT_MIN;
        int MaxLevel = 1;
        int Level = 1;

        while(!BFS.empty())
        {
            int Sum = 0;
            int Range = BFS.size();
            for(int i = 0; i < Range; i++)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();

                Sum += Node->val;
                if(Node->left)
                {
                    BFS.push(Node->left);
                }
                if(Node->right)
                {
                    BFS.push(Node->right);
                }
            }

            if(Max < Sum)
            {
                Max = Sum;
                MaxLevel = Level;
            }
            Level++;
        }

        return MaxLevel;
    }
};