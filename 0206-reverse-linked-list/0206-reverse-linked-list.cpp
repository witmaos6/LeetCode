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
    ListNode* Reverse;
public:
    ListNode* reverseList(ListNode* Head)
    {
        if(!Head)
        {
            return Head;
        }
        ReverseList(Head, nullptr);
        
        return Reverse;
    }
    
private:
    ListNode* ReverseList(ListNode* Head, ListNode* Prev)
    {
        if(!Head->next)
        {
            Head->next = Prev;
            Reverse = Head;
            return Head->next;
        }
        
        ListNode* NewHead = ReverseList(Head->next, Head);
        
        NewHead->next = Prev;
        return Prev;
    }
};