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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        if(head == nullptr)
            return nullptr;
        
        if(head->next == nullptr)
            return head;
        
        int Val1 = head->val;
        int Val2 = head->next->val;
        int NewValue = GCD(Val1, Val2);
        
        ListNode* NewNode = new ListNode(NewValue, head->next);
        head->next = NewNode;
        
        insertGreatestCommonDivisors(NewNode->next);
        
        return head;
    }
    
private:
    int GCD(int A, int B)
    {
        if(B > A)
            swap(A, B);
        
        int C = A % B;
        while(B > 0)
        {
            C = A % B;
            A = B;
            B = C;
        }
        return A;
    }
};