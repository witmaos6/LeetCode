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
    using Family = pair<TreeNode*, TreeNode*>;
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        stack<Family> St;
        queue<TreeNode*> BFS;
        BFS.push(root);
        
        while(!BFS.empty())
        {
            TreeNode* Node = BFS.front();
            BFS.pop();
            
            if(Node->left)
            {
                BFS.push(Node->left);
                St.push({Node, Node->left});
            }
            if(Node->right)
            {
                BFS.push(Node->right);
                St.push({Node, Node->right});
            }
        }
        
        while(!St.empty())
        {
            auto[Parent, Child] = St.top();
            St.pop();
            
            if(Child->left == nullptr && Child->right == nullptr)
            {
                if(Child->val == target)
                {
                    if(Parent->left == Child)
                    {
                        Parent->left = nullptr;
                        delete Child;
                    }
                    if(Parent->right == Child)
                    {
                        Parent->right = nullptr;
                        delete Child;
                    }
                }
            }
        }
        
        if(root->val == target && root->left == nullptr && root->right == nullptr)
            return nullptr;
        
        return root;
    }
};