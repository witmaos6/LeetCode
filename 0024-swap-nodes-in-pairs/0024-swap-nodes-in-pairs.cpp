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
        
        return SwapPairs(head, head->next);
    }
    
private:
    ListNode* SwapPairs(ListNode* First, ListNode* Second)
    {
        if(!Second)
        {
            return First;
        }
        
        if(Second->next)
        {
            ListNode* Temp = SwapPairs(Second->next, Second->next->next);
            Second->next = First;
            First->next = Temp;
        }
        else
        {
            Second->next = First;
            First->next = nullptr;
        }
        
        return Second;
    }
};