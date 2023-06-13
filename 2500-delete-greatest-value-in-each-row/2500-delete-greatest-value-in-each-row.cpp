class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid)
    {
        const int RowSize = static_cast<int>(grid.size());
        const int ColSize = static_cast<int>(grid[0].size());
        
        vector<priority_queue<int, vector<int>>> MaxHeap(RowSize);
        
        for(int Row = 0; Row < RowSize; Row++)
        {
            for(int& Num : grid[Row])
            {
                MaxHeap[Row].push(Num);
            }
        }
        
        int Answer = 0;
        
        for(int Col = 0; Col < ColSize; Col++)
        {
            int MaxValue = 0;
            
            for(int Row = 0; Row < RowSize; Row++)
            {
                MaxValue = max(MaxValue, MaxHeap[Row].top());
                MaxHeap[Row].pop();
            }
            
            Answer += MaxValue;
        }
        
        return Answer;
    }
};