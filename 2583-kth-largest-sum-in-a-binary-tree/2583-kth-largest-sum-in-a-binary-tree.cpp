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
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> MinHeap;
        queue<TreeNode*> BFS;
        BFS.push(root);
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            long long Sum = 0;
            
            for(size_t i = 0; i < Range; i++)
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
            
            MinHeap.push(Sum);
            if(MinHeap.size() > k)
            {
                MinHeap.pop();
            }
        }
        
        if(MinHeap.size() == k)
        {
            return MinHeap.top();
        }
        return -1;
    }
};