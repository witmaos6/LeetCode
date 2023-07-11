/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        unordered_map<TreeNode*, TreeNode*> Parents;
        queue<TreeNode*> BFS;
        BFS.push(root);
        while(!BFS.empty())
        {
            TreeNode* Node = BFS.front();
            BFS.pop();
            
            if(Node->left)
            {
                Parents[Node->left] = Node;
                BFS.push(Node->left);
            }
            if(Node->right)
            {
                Parents[Node->right] = Node;
                BFS.push(Node->right);
            }
        }
        
        unordered_map<TreeNode*, bool> Visited;
        BFS.push(target);
        Visited[target] = true;
        int Level = 0;
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            if(Level == k)
                break;
            Level++;
            
            while(Range--)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();
                
                if(Node->left && !Visited[Node->left])
                {
                    BFS.push(Node->left);
                    Visited[Node->left] = true;
                }
                if(Node->right && !Visited[Node->right])
                {
                    BFS.push(Node->right);
                    Visited[Node->right] = true;
                }
                
                if(Parents[Node] && !Visited[Parents[Node]])
                {
                    BFS.push(Parents[Node]);
                    Visited[Parents[Node]] = true;
                }
            }
        }
        
        vector<int> Result;
        while(!BFS.empty())
        {
            TreeNode* Node = BFS.front();
            BFS.pop();
            Result.push_back(Node->val);
        }
        
        return Result;
    }
};