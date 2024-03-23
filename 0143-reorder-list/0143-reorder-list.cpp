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
    void reorderList(ListNode* head)
    {   
        if (!head || !head->next || !head->next->next)
            return;

        ListNode* Slow = head;
        ListNode* Fast = head;
        while (Fast->next && Fast->next->next)
        {
            Slow = Slow->next;
            Fast = Fast->next->next;
        }

        ListNode* Prev = nullptr;
        ListNode* Curr = Slow->next;
        ListNode* Next;
        while (Curr)
        {
            Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }
        Slow->next = nullptr;

        ListNode* Odd = head;
        ListNode* Even = Prev;
        while (Odd && Even)
        {
            ListNode* OddNext = Odd->next;
            ListNode* EvenNext = Even->next;

            Odd->next = Even;
            Even->next = OddNext;

            Odd = OddNext;
            Even = EvenNext;
        }
    }
};