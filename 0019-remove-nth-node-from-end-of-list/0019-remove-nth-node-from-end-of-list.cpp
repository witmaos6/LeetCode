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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* Traverse = head;
        int Size = 0;
        while(Traverse != nullptr)
        {
            Traverse = Traverse->next;
            Size++;
        }        
        
        if(Size - n == 0)
            return head->next;
        
        ListNode* PrevRemoveNode = head;
        for(int i = 0; i < Size - n - 1; i++)
        {
            PrevRemoveNode = PrevRemoveNode->next;
        }
        
        ListNode* DeleteNode = PrevRemoveNode->next;
        PrevRemoveNode->next = PrevRemoveNode->next->next;
        
        delete DeleteNode;
       
        return head;
    }
};