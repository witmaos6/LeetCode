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
    ListNode* swapPairs(ListNode* head)
    {
        if(!head)
        {
            return nullptr;
        }
        if(head->next)
        {
            ListNode* Next = head->next;
            
            if(Next->next)
            {
                ListNode* Temp = Next->next;

                Next->next = head;
                head->next = swapPairs(Temp);
            }
            else
            {
                Next->next = head;
                head->next = nullptr;
            }
            return Next;
        }
        
        return head;
    }
};