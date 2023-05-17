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
        ListNode* Slow = head;
        ListNode* Fast = head;
        
        while(Fast && Fast->next)
        {
            Sum.push_back(Slow->val);
            
            Slow = Slow->next;
            Fast = Fast->next->next;
        }
        
        int Index = static_cast<int>(Sum.size()) - 1;
        int MaxSum = 0;
        
        while(Slow)
        {
            int CurrSum = Sum[Index] + Slow->val;
            MaxSum = max(MaxSum, CurrSum);
            Index--;
            Slow = Slow->next;
        }
        
        return MaxSum;
    }
};