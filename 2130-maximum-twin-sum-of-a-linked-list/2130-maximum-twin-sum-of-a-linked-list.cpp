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
    int pairSum(ListNode* head) 
    {
        vector<int> Sum;
        
        while(head)
        {
            Sum.push_back(head->val);
            head = head->next;
        }
        
        int Low = 0, High = Sum.size() - 1;
        int MaxSum = 0;
        
        while(Low < High)
        {
            int CurrSum = Sum[Low] + Sum[High];
            MaxSum = max(MaxSum, CurrSum);
            Low++;
            High--;
        }
        
        return MaxSum;
    }
};