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
    vector<ListNode*> Result;
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        Result.resize(k);
        if(head == nullptr)
        {
            return Result;
        }
        
        int N = GetListLength(head);
        
        if(N <= k)
        {
            Result[0] = head;
            int i = 1;
            head = head->next;
            
            while(head)
            {
                Result[i] = head;
                Result[i - 1]->next = nullptr;
                
                head = head->next;
                i++;
            }
        }
        else
        {
            int OverSize = N % k;
            int SplitRange = N / k;
            int i = 1;
            int Range = 1;
            Result[0] = head;
            
            while(head && head->next)
            {
                int Add = (OverSize > 0) ? 1 : 0;
                
                if(Range >= SplitRange + Add)
                {
                    ListNode* Temp = head;
                    head = head->next;

                    Result[i] = head;
                    i++;
                    Temp->next = nullptr;
                    Range = 1;
                    
                    OverSize--;
                }
                else
                {
                    head = head->next;
                    Range++;
                }
            }
        }
        
        return Result;
    }
    
private:
    int GetListLength(ListNode* Head)
    {
        int Length = 0;
        while(Head)
        {
            Head = Head->next;
            Length++;
        }
        
        return Length;
    }
};