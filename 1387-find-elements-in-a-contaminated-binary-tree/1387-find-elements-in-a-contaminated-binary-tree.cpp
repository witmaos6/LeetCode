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
class FindElements {
    unordered_set<int> Table;
public:
    FindElements(TreeNode* root)
    {
        if(root)
        {
            root->val = 0;
            Table.insert(0);
            if(root->left)
            {
                DFS(root->left, 0, true);
            }
            if(root->right)
            {
                DFS(root->right, 0, false);
            }
        }
    }
    
    bool find(int target)
    {
        if(Table.count(target))
        {
            return true;
        }
        return false;
    }
private:
    void DFS(TreeNode* Node, int Parent, bool IsLeft)
    {
        if(Node)
        {
            int Temp = IsLeft ? 1 : 2;
            Node->val = Parent * 2 + Temp;
            Table.insert(Node->val);
            if(Node->left)
            {
                DFS(Node->left, Node->val, true);
            }
            if(Node->right)
            {
                DFS(Node->right, Node->val, false);
            }
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */