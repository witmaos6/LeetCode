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
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == nullptr)
            return nullptr;
        
        if(head->next == nullptr || k == 0)
            return head;

        ListNode* Curr = head;
        ListNode* First = head;

        int N = 1;
        while(Curr->next)
        {
            Curr = Curr->next;
            N++;
        }

        Curr->next = First;
        int Pos = N + (-k) % N;
        ListNode* Result = head;
        ListNode* Prev;
        for(int i = 0; i < Pos; i++)
        {
            Prev = Result;
            Result = Result->next;
        }
        Prev->next = nullptr;
        return Result;
    }
};