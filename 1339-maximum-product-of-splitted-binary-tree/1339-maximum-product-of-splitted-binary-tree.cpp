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
class Solution 
{
    vector<int> Arr;
public:
    int maxProduct(TreeNode* root) 
    {
        const int Mod = 1e9 + 7;
        long long Result = 0;
        DFS(root);

        for (int& i : Arr)
        {
            Result = max((long long) i * (Arr[0] - i), Result);
        }

        return Result % Mod;
    }

private:
    int DFS(TreeNode* Node) 
    {
        if (Node)
        {
            size_t Cur = Arr.size();
            Arr.push_back(Node->val);
            Arr[Cur] += DFS(Node->left) + DFS(Node->right);
            return Arr[Cur];
        }
        return 0;
    }
};