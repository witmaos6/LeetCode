class Solution {
    using Point = tuple<int, int, int>;
public:
    int swimInWater(vector<vector<int>>& grid)
    {
        const int Rows = static_cast<int>(grid.size());
        const int Cols = static_cast<int>(grid[0].size());

        priority_queue<Point, vector<Point>, greater<>> MinHeap;
        vector<int> Dir = {-1, 0, 1, 0, -1};
        set<pair<int, int>> Visited;

        MinHeap.push({grid[0][0], 0, 0});

        while(!MinHeap.empty())
        {
            auto[Cost, R, C] = MinHeap.top();
            MinHeap.pop();

            if(Visited.count({R, C}))
                continue;
            Visited.insert({R, C});

            if(R == Rows - 1 && C == Cols - 1)
                return Cost;

            for(int i = 0; i < 4; i++)
            {
                int DR = R + Dir[i];
                int DC = C + Dir[i + 1];

                if(DR >= 0 && DR < Rows && DC >= 0 && DC < Cols && !Visited.count({DR, DC}))
                {
                    int NewCost = max(Cost, grid[DR][DC]);
                    MinHeap.push({NewCost, DR, DC});
                }
            }            
        }
        return -1;
    }
};