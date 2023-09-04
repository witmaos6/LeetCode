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
        
        return HasCycle(head, head->next);
    }
    
private:
    bool HasCycle(ListNode* Slow, ListNode* Fast)
    {
        if(Slow == nullptr || Fast == nullptr || Fast->next == nullptr)
        {
            return false;
        }
        
        if(Slow == Fast)
        {
            return true;
        }
        
        return HasCycle(Slow->next, Fast->next->next);
    }
};