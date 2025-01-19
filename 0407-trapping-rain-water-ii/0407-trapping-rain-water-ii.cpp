class Solution {
    int Rows = 0;
    int Cols = 0;
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        Rows = static_cast<int>(heightMap.size());
        Cols = static_cast<int>(heightMap[0].size());

        vector<vector<int>> Graph(Rows * Cols + 1);
        int VirtualStart = Rows * Cols;

        array<array<int, 2>, 4> Dir = {{{0,1}, {0,-1},{1,0},{-1,0}}};

        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                int CurrCell = Row * Cols + Col;

                if(Row == 0 || Row == Rows - 1 || Col == 0 || Col == Cols - 1)
                {
                    Graph[VirtualStart].push_back(CurrCell);
                }

                for(int i = 0; i < 4; i++)
                {
                    int DRow = Row + Dir[i][0];
                    int DCol = Col + Dir[i][1];

                    if(InBoundary(DRow, DCol))
                    {
                        Graph[CurrCell].push_back(DRow * Cols + DCol);
                    }
                }
            }
        }

        vector<int> Dist = CalculateDistanceWithDijkstra(VirtualStart, Graph, heightMap);

        int TrappedWater = 0;
        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                int Cell = Row * Cols + Col;
                int BoundaryHeight = Dist[Cell];
                if(BoundaryHeight > heightMap[Row][Col])
                {
                    TrappedWater += (BoundaryHeight - heightMap[Row][Col]);
                }
            }
        }

        return TrappedWater;
    }
private:
    bool InBoundary(const int Row, const int Col)
    {
        if(Row >= 0 && Row < Rows && Col >= 0 && Col < Cols)
            return true;
        
        return false;
    }

    vector<int> CalculateDistanceWithDijkstra(const int Start, const vector<vector<int>>& Graph, const vector<vector<int>>& HeightMap)
    {
        vector<int> Dist(Graph.size(), INT_MAX / 2);
        Dist[Start] = 0;

        set<pair<int, int>> MinHeap; // 특정 데이터를 지우기 위해 Set을 사용
        MinHeap.insert({0, Start});

        while(!MinHeap.empty())
        {
            auto [CurrDistance, CurrNode] = *MinHeap.begin();
            MinHeap.erase(MinHeap.begin());

            for(const int& Neighbor : Graph[CurrNode])
            {
                int Weight = HeightMap[Neighbor / Cols][Neighbor % Cols];
                if(max(CurrDistance, Weight) < Dist[Neighbor])
                {
                    MinHeap.erase({Dist[Neighbor], Neighbor});
                    Dist[Neighbor] = max(CurrDistance, Weight);
                    MinHeap.insert({Dist[Neighbor], Neighbor});
                }
            }
        }
        return Dist;
    }
};