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
        if(!head || !head->next)
        {
            return head;
        }
        
        ListNode* First = head;
        ListNode* Second = head->next;
        
        head = head->next;
        int Max = 100;
        
        while(Max--)
        {
            ListNode* Temp = Second->next;
            Second->next = First;
            First->next = Temp;
            
            if(First->next && First->next->next)
            {
                First->next = Temp->next;
                First = Temp;
                Second = Temp->next;
            }
            else
            {
                break;
            }
        }
        
        return head;
    }
};