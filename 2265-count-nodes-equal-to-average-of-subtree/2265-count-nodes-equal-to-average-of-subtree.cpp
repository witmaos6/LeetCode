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
    int NrOfAverageNode = 0;
    typedef pair<int, int> Sub;
public:
    int averageOfSubtree(TreeNode* root)
    {
        PostOrder(root);
        
        return NrOfAverageNode;
    }
    
private:
    Sub PostOrder(TreeNode* Root)
    {
        if(Root == nullptr)
        {
            return {0, 0};
        }
        
        Sub RightSub = PostOrder(Root->right);
        Sub LeftSub = PostOrder(Root->left);
        
        int TotalSum = Root->val + RightSub.first + LeftSub.first;
        
        int NrOfNode = 1;
        NrOfNode += RightSub.second + LeftSub.second;
        
        int Average = TotalSum / NrOfNode;
        
        if(Root->val == Average)
        {
            NrOfAverageNode++;
        }
        
        return {TotalSum, NrOfNode};
    }
};