class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points)
    {
        const size_t N = points.size();
        
        priority_queue<int, vector<int>, greater<>> MinHeap;
        for(size_t i = 0; i < N; i++)
        {
            MinHeap.push(points[i][0]);
        }
        
        int PrevNum = MinHeap.top();
        int MaxWidth = 0;
        
        while(!MinHeap.empty())
        {
            int CurrNum = MinHeap.top();
            MinHeap.pop();
            
            int Diff = CurrNum - PrevNum;
            
            MaxWidth = max(MaxWidth, Diff);
            
            PrevNum = CurrNum;
        }
        
        return MaxWidth;
    }
};