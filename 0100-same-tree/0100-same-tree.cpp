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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p == nullptr && q == nullptr)
        {
            return true;
        }
        else if(p == nullptr || q == nullptr)
        {
            return false;
        }
        queue<TreeNode*> BFS1;
        queue<TreeNode*> BFS2;
        BFS1.push(p);
        BFS2.push(q);
        
        while(!BFS1.empty() && !BFS2.empty())
        {
            TreeNode* Node1 = BFS1.front();
            BFS1.pop();
            TreeNode* Node2 = BFS2.front();
            BFS2.pop();
            
            if(Node1->val != Node2->val)
            {
                return false;
            }
            if(Node1->left && Node2->left)
            {
                BFS1.push(Node1->left);
                BFS2.push(Node2->left);
            }
            else if(Node1->left == nullptr && Node2->left == nullptr)
            {
                
            }
            else
            {
                return false;
            }
            if(Node1->right && Node2->right)
            {
                BFS1.push(Node1->right);
                BFS2.push(Node2->right);
            }
            else if(Node1->right == nullptr && Node2->right == nullptr)
            {
                
            }
            else
            {
                return false;
            }
        }
        
        if(!BFS1.empty() || !BFS2.empty())
        {
            return false;
        }
        return true;
    } 
};