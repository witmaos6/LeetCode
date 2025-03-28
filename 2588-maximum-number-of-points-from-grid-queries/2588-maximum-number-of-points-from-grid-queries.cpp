class Solution {
    using Pair = pair<int, int>;
    using Point = pair<int, Pair>;
    int Dir[5] = {0, 1, 0, -1, 0};
    int Rows = 0;
    int Cols = 0;
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries)
    {
        Rows = static_cast<int>(grid.size());
        Cols = static_cast<int>(grid[0].size());
        const int QuerySize = static_cast<int>(queries.size());

        vector<Pair> QueryToIndex(QuerySize);
        for(int i = 0; i < QuerySize; i++)
        {
            QueryToIndex[i] = {queries[i], i};
        }
        sort(QueryToIndex.begin(), QueryToIndex.end());

        priority_queue<Point, vector<Point>, greater<>> MinHeap;
        MinHeap.push({grid[0][0], {0,0}});
        vector<vector<bool>> Visited(Rows, vector<bool>(Cols));
        Visited[0][0] = true;
        int Count = 0;
        vector<int> Result(QuerySize);
        for(auto& [Query, Index] : QueryToIndex)
        {
            while(!MinHeap.empty() && MinHeap.top().first < Query)
            {
                auto[Value, P] = MinHeap.top();
                MinHeap.pop();

                auto [Row, Col] = P;
                Count++;

                for(int i = 0; i < 4; i++)
                {
                    int DRow = Row + Dir[i];
                    int DCol = Col + Dir[i + 1];
                    if(!InBoundary(DRow, DCol) || Visited[DRow][DCol])
                        continue;
                    MinHeap.push({grid[DRow][DCol], {DRow, DCol}});
                    Visited[DRow][DCol] = true;
                }
            }
            Result[Index] = Count;
        }
        return Result;
    }

private:
    bool InBoundary(const int Row, const int Col)
    {
        if(Row >= 0 && Row < Rows && Col >= 0 && Col < Cols)
            return true;

        return false;
    }
};