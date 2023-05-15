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
    int Size = 0;
    ListNode* FromBeginPrev;
    ListNode* FromEndPrev;
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        if(head->next == nullptr)
        {
            return head;
        }
        
        Traverse(head, 1, k);
        
        swap(FromBeginPrev->val, FromEndPrev->val);
        
        return head;
    }
    
private:
    void Traverse(ListNode* Head, int Index, int K)
    {
        if(!Head)
        {
            Size = Index - 1;
            return;
        }
        
        if(Index == K)
        {
            FromBeginPrev = Head;
        }
        Traverse(Head->next, Index + 1, K);
        
        if(Size - K + 1 == Index)
        {
            FromEndPrev = Head;
        }
    }
};