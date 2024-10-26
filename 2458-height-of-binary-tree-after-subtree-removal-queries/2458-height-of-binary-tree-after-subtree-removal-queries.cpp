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
    vector<int> MaxHeights;
    int CurrMaxHeight = 0;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries)
    {
        MaxHeights.resize(100001);
        DFSLeftToRight(root, 0);
        CurrMaxHeight = 0;
        DFSRightToLeft(root, 0);
        
        const int M = static_cast<int>(queries.size());
        vector<int> QueryResult(M);
        
        for(int i = 0; i < M; ++i)
        {
            QueryResult[i] = MaxHeights[queries[i]];
        }
        
        return QueryResult;
    }
    
private:
    void DFSLeftToRight(TreeNode* Root, const int CurrHeight)
    {
        if(Root == nullptr)
            return;
        
        MaxHeights[Root->val] = CurrMaxHeight;
        
        CurrMaxHeight = max(CurrMaxHeight, CurrHeight);
        
        DFSLeftToRight(Root->left, CurrHeight + 1);
        DFSLeftToRight(Root->right, CurrHeight + 1);
    }
    
    void DFSRightToLeft(TreeNode* Root, const int CurrHeight)
    {
        if(Root == nullptr)
            return;
        
        MaxHeights[Root->val] = max(MaxHeights[Root->val], CurrMaxHeight);
        
        CurrMaxHeight = max(CurrMaxHeight, CurrHeight);
        
        DFSRightToLeft(Root->right, CurrHeight + 1);
        DFSRightToLeft(Root->left, CurrHeight + 1);
    }
};