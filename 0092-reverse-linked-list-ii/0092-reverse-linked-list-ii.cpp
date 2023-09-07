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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* LeftNode = head;
        int Index = 1;
        while(Index < left)
        {
            LeftNode = LeftNode->next;
            Index++;
        }
        
        ListNode* Temp = LeftNode;
        
        stack<int> Reverse;
        while(Index <= right)
        {
            Reverse.push(LeftNode->val);
            LeftNode = LeftNode->next;
            Index++;
        }
        
        
        while(!Reverse.empty())
        {
            Temp->val = Reverse.top();
            Reverse.pop();
            Temp = Temp->next;
        }
        
        return head;
    }
};