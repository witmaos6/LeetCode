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
                if(head)
                {
                    Matrix[RowBegin][Col] = head->val;
                    head = head->next;
                }
                else
                {
                    Matrix[RowBegin][Col] = Empty;
                }
            }
            RowBegin++;
            
            for(int Row = RowBegin; Row <= RowEnd; Row++)
            {
                if(head)
                {
                    Matrix[Row][ColEnd] = head->val;
                    head = head->next;
                }
                else
                {
                    Matrix[Row][ColEnd] = Empty;
                }
                
            }
            ColEnd--;
            
            if(RowBegin > RowEnd || ColBegin > ColEnd)
                break;
            
            for(int Col = ColEnd; Col >= ColBegin; Col--)
            {
                if(head)
                {
                    Matrix[RowEnd][Col] = head->val;
                    head = head->next;
                }
                else
                {
                    Matrix[RowEnd][Col] = Empty;
                }
            }
            RowEnd--;
            
            for(int Row = RowEnd; Row >= RowBegin; Row--)
            {
                if(head)
                {
                    Matrix[Row][ColBegin] = head->val;
                    head = head->next;
                }
                else
                {
                    Matrix[Row][ColBegin] = Empty;
                }
            }
            ColBegin++;
        }
        
        return Matrix;
    }
};