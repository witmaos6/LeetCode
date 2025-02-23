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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
    {
        stack<TreeNode*> Nodes;
        TreeNode* Root = new TreeNode(preorder[0]);
        Nodes.push(Root);

        int PreIndex = 1;
        int PostIndex = 0;

        while(!Nodes.empty())
        {
            TreeNode* Current = Nodes.top();

            if(Current->val == postorder[PostIndex])
            {
                Nodes.pop();
                PostIndex++;
            }
            else
            {
                TreeNode* NewNode = new TreeNode(preorder[PreIndex]);
                PreIndex++;

                if(!Current->left)
                {
                    Current->left = NewNode;
                }
                else
                {
                    Current->right = NewNode;
                }
                Nodes.push(NewNode);
            }
        }

        return Root;
    }
};