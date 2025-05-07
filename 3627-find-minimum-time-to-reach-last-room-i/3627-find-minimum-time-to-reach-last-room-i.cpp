class Solution {
    using Tuple = tuple<int, int, int>;
    array<int, 5> Dir = {0, 1, 0, -1, 0};
    int Rows = 0;
    int Cols = 0;
public:
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        Rows = static_cast<int>(moveTime.size());
        Cols = static_cast<int>(moveTime[0].size());
        vector<vector<int>> Memo(Rows, vector<int>(Cols, INT_MAX));

        priority_queue<Tuple, vector<Tuple>, greater<Tuple>> MinHeap;
        MinHeap.emplace(0,0,0);
        Memo[0][0] = 0;

        while(!MinHeap.empty())
        {
            auto[Time, Row, Col] = MinHeap.top();
            MinHeap.pop();

            if(Row == Rows - 1 && Col == Cols - 1)
                return Time;

            for(int i = 0; i < 4; i++)
            {
                int DRow = Row + Dir[i];
                int DCol = Col + Dir[i + 1];

                if(!InBoundary(DRow, DCol))
                    continue;

                int NextTime = max(Time, moveTime[DRow][DCol]) + 1;
                if(NextTime < Memo[DRow][DCol])
                {
                    Memo[DRow][DCol] = NextTime;
                    MinHeap.emplace(NextTime, DRow, DCol);
                }
            }
        }

        return -1;
    }

private:
    bool InBoundary(const int Row, const int Col)
    {
        if(Row >= 0 && Row < Rows && Col >= 0 && Col < Cols)
            return true;
        return false;
    }
};