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
    const int Empty = -1;
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
    {
        vector<vector<int>> Matrix(m, vector<int>(n));
        
        int RowBegin = 0, RowEnd = m - 1;
        int ColBegin = 0, ColEnd = n - 1;
        
        while(RowBegin <= RowEnd && ColBegin <= ColEnd)
        {
            for(int Col = ColBegin; Col <= ColEnd; Col++)
            {
                Matrix[RowBegin][Col] = SetMatrixCell(head);
            }
            RowBegin++;
            
            for(int Row = RowBegin; Row <= RowEnd; Row++)
            {
                Matrix[Row][ColEnd] = SetMatrixCell(head);
            }
            ColEnd--;
            
            if(RowBegin > RowEnd || ColBegin > ColEnd)
                break;
            
            for(int Col = ColEnd; Col >= ColBegin; Col--)
            {
                Matrix[RowEnd][Col] = SetMatrixCell(head);
            }
            RowEnd--;
            
            for(int Row = RowEnd; Row >= RowBegin; Row--)
            {
                Matrix[Row][ColBegin] = SetMatrixCell(head);
            }
            ColBegin++;
        }
        
        return Matrix;
    }
    
private:
    int SetMatrixCell(ListNode* head)
    {
        if(head)
        {
            int Cell = head->val;
            
            if(head->next)
            {
                *head = *head->next;
            }
            else
            {
                head->val = Empty;
            }
            return Cell;
        }
        return Empty;
    }
};