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
    bool isEvenOddTree(TreeNode* root)
    {
        queue<TreeNode*> BFS;
        BFS.push(root);
        int Index = 0;
        
        while(!BFS.empty())
        {
            size_t Range = BFS.size();
            vector<int> Level;
            for(size_t i = 0; i < Range; i++)
            {
                TreeNode* Node = BFS.front();
                BFS.pop();
                
                Level.push_back(Node->val);
                if(Node->left)
                {
                    BFS.push(Node->left);
                }
                if(Node->right)
                {
                    BFS.push(Node->right);
                }
            }
            if(Index & 1)
            {
                if(!ValidOddIndex(Level))
                {
                    return false;
                }
            }
            else
            {
                if(!ValidEvenIndex(Level))
                {
                    return false;
                }
            }
            
            Index++;
        }
        return true;
    }
    
private:
    bool ValidEvenIndex(const vector<int>& Arr)
    {
        int N = static_cast<int>(Arr.size());
        int ValidIncreasing = 0;
        for(int i = 0; i < N; i++)
        {
            if(ValidIncreasing >= Arr[i] || (Arr[i] & 1) == 0)
            {
                return false;
            }
            ValidIncreasing = Arr[i];
        }
        return true;
    }
    
    bool ValidOddIndex(const vector<int>& Arr)
    {
        int N = static_cast<int>(Arr.size());
        int ValidDecreasing = INT_MAX;
        for(int i = 0; i < N; i++)
        {
            if(ValidDecreasing <= Arr[i] || (Arr[i] & 1) == 1)
            {
                return false;
            }
            ValidDecreasing = Arr[i];
        }
        return true;
    }
};