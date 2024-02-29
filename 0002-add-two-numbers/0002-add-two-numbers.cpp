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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int Temp = 0;
        ListNode NewHead(0);
        ListNode *H = &NewHead;

        while(Temp == 1 || l1 || l2) 
        {
            Temp += (l1? l1->val : 0) + (l2? l2->val : 0);

            int Digit = (Temp >= 10) ? Temp - 10 : Temp;
            
            H->next = new ListNode(Digit);
            H = H->next;
            
            Temp = (Temp >= 10) ? 1 : 0;

            if(l1)
            {
                l1 = l1->next;
            }
            if(l2)
            {
                l2 = l2->next;
            }
        }

        return NewHead.next;
    }
};