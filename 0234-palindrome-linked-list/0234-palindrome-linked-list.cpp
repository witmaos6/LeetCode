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
    bool isPalindrome(ListNode* head)
    {
        ListNode* Slow = head;
        ListNode* Fast = head;
        ListNode* Prev = nullptr;
        
        while(Fast && Fast->next)
        {
            Fast = Fast->next->next;
            
            ListNode* Temp = Slow->next;
            Slow->next = Prev;
            Prev = Slow;
            Slow = Temp;
        }
        
        if(Fast)
        {
            Slow = Slow->next;
        }
        
        while(Slow)
        {
            if(Prev->val != Slow->val)
            {
                return false;
            }
            Prev = Prev->next;
            Slow = Slow->next;
        }
        
        return true;
    }
};