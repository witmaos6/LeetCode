class Solution {
    int RowSize = 0;
    int ColSize = 0;
    typedef pair<int, int> RowPoint;
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
    {
        RowSize = static_cast<int>(mat.size());
        ColSize = static_cast<int>(mat[0].size());
        
        priority_queue<RowPoint, vector<RowPoint>, greater<>> MinHeap;
        
        for(int i = 0; i < RowSize; i++)
        {
            int Soldiers = GetNrOfSoldiers(mat[i]);
            MinHeap.push({Soldiers, i});
        }
        
        vector<int> Result(k);
        
        for(int i = 0; i < k; i++)
        {
            Result[i] = MinHeap.top().second;
            MinHeap.pop();
        }
        
        return Result;
    }
    
private:
    int GetNrOfSoldiers(vector<int>& Row)
    {
        int Left = 0, Right = ColSize - 1;
        
        while(Left <= Right)
        {
            int Middle = (Right + Left) / 2;
            
            if(Row[Middle] == 1)
            {
                Left = Middle + 1;
            }
            else if(Row[Middle] == 0)
            {
                Right = Middle - 1;
            }
        }
        
        return Left;
    }
};