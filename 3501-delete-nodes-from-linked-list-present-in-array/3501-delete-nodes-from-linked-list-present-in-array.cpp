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
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> Table;
        for(int& x : nums)
        {
            Table.insert(x);
        }

        ListNode* NewHead= new ListNode(-1);
        ListNode* Temp = NewHead;

        while(head)
        {
            if(Table.count(head->val) == 0)
            {
                NewHead->next = new ListNode(head->val);
                NewHead = NewHead->next;
            }
            head = head->next;
        }
        return Temp->next;
    }
};