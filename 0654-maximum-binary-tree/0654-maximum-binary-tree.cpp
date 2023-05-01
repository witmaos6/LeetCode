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
    int N = 0;
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        N = static_cast<int>(nums.size());
        
        TreeNode* Root = constructMaximumBinaryTree(nums, 0, N, Root);
        
        return Root;
    }
    
private:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int Begin, int End, TreeNode* Root)
    {
        if(Begin == End)
        {
            if(nums[Begin] == -1)
            {
                return nullptr;
            }
            return new TreeNode(nums[Begin]);
        }
        
        int MaxElement = max_element(nums.begin() + Begin, nums.begin() + End) - nums.begin();
        if(nums[MaxElement] == -1)
        {
            return nullptr;
        }
        
        Root = new TreeNode(nums[MaxElement]);
        nums[MaxElement] = -1;
        
        if(MaxElement > Begin)
        {
            Root->left = constructMaximumBinaryTree(nums, Begin, MaxElement, Root->left);
        }
        if(MaxElement < End - 1)
        {
            Root->right = constructMaximumBinaryTree(nums, MaxElement + 1, End, Root->right);
        }
        
        return Root;
    }
};