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
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        vector<int> CriticalPoint;
        int PreValue = 0;
        int Index = 0;
        
        while(head)
        {
            if(PreValue != 0)
            {
                if(PreValue < head->val)
                {
                    if(head->next && head->val > head->next->val)
                    {
                        CriticalPoint.push_back(Index);
                    }
                }
                else if(PreValue > head->val)
                {
                    if(head->next && head->val < head->next->val)
                    {
                        CriticalPoint.push_back(Index);
                    }
                }
            }
            
            PreValue = head->val;
            Index++;
            head = head->next;
        }
        
        if(CriticalPoint.size() <= 1)
        {
            return {-1, -1};
        }
        
        vector<int> Result(2, INT_MAX);
        Result[1] = CriticalPoint.back() - CriticalPoint.front();
        
        const int Size = static_cast<int>(CriticalPoint.size());
        for(int i = 0; i < Size - 1; i++)
        {
            int Temp = CriticalPoint[i + 1] - CriticalPoint[i];
            Result[0] = min(Result[0], Temp);
        }
        
        return Result;
    }
};