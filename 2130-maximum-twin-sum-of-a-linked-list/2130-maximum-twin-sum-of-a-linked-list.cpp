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
    int pairSum(ListNode* head)
    {
        ListNode* Middle = MiddleNode(head);
        ListNode* Second = Middle->next;
        Middle->next = nullptr;
        ListNode* First = Reverse(head);

        int Result = 0;
        while(First)
        {
            Result = max(Result, First->val + Second->val);
            First = First->next;
            Second = Second->next;
        }
        return Result;
    }

private:
    ListNode* MiddleNode(ListNode* Head)
    {
        ListNode* Slow = Head;
        ListNode* Fast = Head;

        while(Fast->next && Fast->next->next)
        {
            Slow = Slow->next;
            Fast = Fast->next->next;
        }
        return Slow;
    }

    ListNode* Reverse(ListNode* Head)
    {
        ListNode* Prev = nullptr;
        ListNode* Curr = Head;

        while(Curr)
        {
            ListNode* Temp = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Temp;
        }
        return Prev;
    }
};