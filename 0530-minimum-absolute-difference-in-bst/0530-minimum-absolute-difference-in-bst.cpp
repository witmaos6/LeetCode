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
    vector<int> Node;
public:
    int getMinimumDifference(TreeNode* root)
    {
        Inorder(root);
        
        const size_t N = Node.size();
        
        int MinDiffer = INT_MAX;
        for(size_t i = 1; i < N; i++)
        {
            int Temp = Node[i] - Node[i - 1];
            MinDiffer = min(MinDiffer, Temp);
        }
        
        return MinDiffer;
    }
    
private:
    void Inorder(TreeNode* Root)
    {
        if(Root)
        {
            Inorder(Root->left);
            Node.push_back(Root->val);
            Inorder(Root->right);
        }
    }
};