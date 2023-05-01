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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        int N = static_cast<int>(nums.size());
        
        TreeNode* Root = constructMaximumBinaryTree(nums, 0, N - 1);
        
        return Root;
    }
    
private:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int Begin, int End)
    {
        if(Begin > End)
        {
            return nullptr;
        }
        if(Begin == End)
        {
            return new TreeNode(nums[Begin]);
        }
        
        int MaxElement = GetMaxElement(nums, Begin, End);
        
        TreeNode* Root = new TreeNode(nums[MaxElement]);
        Root->left = constructMaximumBinaryTree(nums, Begin, MaxElement - 1);
        Root->right = constructMaximumBinaryTree(nums, MaxElement + 1, End);
        
        return Root;
    }
    
    int GetMaxElement(vector<int>& nums, int Begin, int End)
    {
        int MaxElement = Begin;
        
        for(int i = Begin + 1; i <= End; i++)
        {
            if(nums[MaxElement] < nums[i])
            {
                MaxElement = i;
            }
        }
        return MaxElement;
    }
};