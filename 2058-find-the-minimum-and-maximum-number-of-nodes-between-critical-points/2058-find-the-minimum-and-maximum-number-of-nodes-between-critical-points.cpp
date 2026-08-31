/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<int> Indices;
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        Traverse(nullptr, head, 0);

        if(Indices.size() <= 1)
            return {-1, -1};

        int Max = Indices.back() - Indices.front();
        vector<int> Result = {Max, Max};
        
        const int N = Indices.size();
        for(int i = 1; i < N; i++)
        {
            Result[0] = min(Result[0], Indices[i] - Indices[i - 1]);
        }

        return Result;
    }
private:
    void Traverse(ListNode* Prev, ListNode* Node, int Index)
    {
        if(Prev)
        {
            if(Node->next)
            {
                if(Prev->val < Node->val && Node->next->val < Node->val)
                {
                    Indices.push_back(Index);
                }
                else if(Prev->val > Node->val && Node->next->val > Node->val)
                {
                    Indices.push_back(Index);
                }
            }
            else
            {
                return;
            }
        }
        Traverse(Node, Node->next, Index + 1);
    }
};