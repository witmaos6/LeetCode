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
            BFS(root);
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
    void BFS(TreeNode* Root)
    {
        if(Root == nullptr)
            return;

        queue<TreeNode*> Q;
        Q.push(Root);

        while(!Q.empty())
        {
            TreeNode* Node = Q.front();
            Q.pop();

            if(Node->left)
            {
                Node->left->val = Node->val * 2 + 1;
                Table.insert(Node->left->val);
                Q.push(Node->left);
            }
            if(Node->right)
            {
                Node->right->val = Node->val * 2 + 2;
                Table.insert(Node->right->val);
                Q.push(Node->right);
            }
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */