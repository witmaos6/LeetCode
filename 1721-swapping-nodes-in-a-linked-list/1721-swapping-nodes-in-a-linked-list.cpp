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
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode* FromBegin = head;
        
        while(k > 1)
        {
            FromBegin = FromBegin->next;
            k--;
        }
        
        ListNode* GoEnd = FromBegin;
        ListNode* FromEnd = head;
        
        while(GoEnd->next)
        {
            FromEnd = FromEnd->next;
            GoEnd = GoEnd->next;
        }
        
        swap(FromBegin->val, FromEnd->val);
        
        return head;
    }
};