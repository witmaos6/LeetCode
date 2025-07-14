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
    int getDecimalValue(ListNode* head)
    {
        if(head == nullptr)
            return 0;

        int Result = 0;
        while(head)
        {
            Result = (Result << 1) + head->val;
            head = head->next;
        }
        return Result;
    }
};