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
    vector<string> Binaries;
public:
    int sumRootToLeaf(TreeNode* root)
    {
        if(!root)
            return 0;

        DFS(root, "");

        int Sum = 0;
        for(string& Binary : Binaries)
        {
            Sum += BinaryToNum(Binary);
        }
        return Sum;
    }

private:
    void DFS(TreeNode* Root, string PrevBinary)
    {
        if(!Root)
            return;

        char Curr = ('0' + Root->val);
        string CurrBinary = PrevBinary + Curr;

        if(Root->left || Root->right)
        {
            if(Root->left)
            {
                DFS(Root->left, CurrBinary);
            }
            if(Root->right)
            {
                DFS(Root->right, CurrBinary);
            }
        }
        else
        {
            Binaries.push_back(CurrBinary);
        }
    }

    int BinaryToNum(const string& Binary)
    {
        const int N = static_cast<int>(Binary.size());
        int Num = 0;
        int Pow = N - 1;
        for(int i = 0; i < N; i++)
        {
            if(Binary[i] == '1')
            {
                Num += pow(2, Pow);
            }
            Pow--;
        }
        return Num;
    }
};