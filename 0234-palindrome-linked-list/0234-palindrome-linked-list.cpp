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
        stack<int> PrevHalf;
        
        ListNode* Slow = head;
        ListNode* Fast = head;
        
        while(Fast && Fast->next)
        {
            PrevHalf.push(Slow->val);
            
            Slow = Slow->next;
            Fast = Fast->next->next;
        }
        
        if(Fast)
        {
            Slow = Slow->next;
        }

        while(Slow)
        {
            if(PrevHalf.top() != Slow->val)
            {
                return false;
            }
            PrevHalf.pop();
            Slow = Slow->next;
        }
        
        return true;
    }
};