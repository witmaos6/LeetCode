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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* Left = new ListNode(0);
        ListNode* Right = new ListNode(0);
        
        Traverse(Left, Right, head, x);
        
        return Left->next;
    }
    
private:
    void Traverse(ListNode* Left, ListNode* Right, ListNode* Head, int X)
    {
        ListNode* RightHead = Right;
        
        while(Head)
        {
            if(Head->val < X)
            {
                Left->next = Head;
                Left = Head;
            }
            else
            {
                Right->next = Head;
                Right = Head;
            }
            
            Head = Head->next;
        }
        
        Right->next = nullptr;
        Left->next = RightHead->next;
    }
};