/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return false;
        }
        
        ListNode* Slow = head;
        ListNode* Fast = head;
        
        while(Fast && Fast->next)
        {
            Slow = Slow->next;
            Fast = Fast->next->next;
            
            if(Slow == Fast)
            {
                return true;
            }
        }
        
        return false;
    }
};