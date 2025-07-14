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

        vector<int> Bits;
        while(head)
        {
            Bits.push_back(head->val);
            head = head->next;
        }

        const int N = static_cast<int>(Bits.size());
        int Result = 0;
        for(int i = N - 1; i >= 0; i--)
        {
            int Num = Bits[i] * pow(2, (N - 1 - i));
            Result += Num;
        }
        return Result;
    }
};