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
struct Family
{
    TreeNode* Parent;
    TreeNode* Child;
    
    Family(){}
    Family(TreeNode* P, TreeNode* C) : Parent(P), Child(C){}
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        queue<Family> BFS;
        if(root)
        {
            root->val = 0;
            if(root->left)
            {
                BFS.push(Family(root, root->left));
            }
            if(root->right)
            {
                BFS.push(Family(root, root->right));
            }
        }
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            
            unordered_map<TreeNode*, int> ChildSum;
            vector<Family> LevelNode;
            int Sum = 0;
                
            for(size_t i = 0; i < Range; i++)
            {
                LevelNode.push_back(BFS.front());
                
                TreeNode* Parent = BFS.front().Parent;
                TreeNode* CurrNode = BFS.front().Child;
                BFS.pop();
                
                Sum += CurrNode->val;
                ChildSum[Parent] += CurrNode->val;
                
                if(CurrNode->left)
                {
                    BFS.push(Family(CurrNode, CurrNode->left));
                }
                if(CurrNode->right)
                {
                    BFS.push(Family(CurrNode, CurrNode->right));
                }
            }
            
            for(Family& Node : LevelNode)
            {
                Node.Child->val = Sum - ChildSum[Node.Parent];
            }
        }
        
        return root;
    }
};