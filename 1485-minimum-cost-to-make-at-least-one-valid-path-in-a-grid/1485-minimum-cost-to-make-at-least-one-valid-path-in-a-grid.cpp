class Solution {
    int Rows = 0;
    int Cols = 0;
public:
    int minCost(vector<vector<int>>& grid)
    {
        Rows = static_cast<int>(grid.size());
        Cols = static_cast<int>(grid[0].size());

        priority_queue<unsigned int, vector<unsigned int>, greater<>> MinHeap;
        vector<unsigned int> Dist(Rows * Cols, UINT_MAX);
        vector<bool> Visited(10000);

        MinHeap.push(Packet(0, 0, 0));
        Dist[0] = 0;
        Visited[0] = true;
        array<array<int, 2>, 4> Dirs = {{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

        while(!MinHeap.empty())
        {
            unsigned int CurrPacket = MinHeap.top();
            MinHeap.pop();

            auto[CountDir, Row, Col] = Receive(CurrPacket);
            Visited[IndexTo1D(Row, Col, Cols)] = true;

            if(Row == Rows - 1 && Col == Cols - 1)
                return CountDir;

            int X = grid[Row][Col];
            for(int i = 0; i < 4; i++)
            {
                int DRow = Row + Dirs[i][0];
                int DCol = Col + Dirs[i][1];
                int Index = IndexTo1D(DRow, DCol, Cols);

                if(!InBoundary(DRow, DCol) || Visited[Index])
                {
                    continue;
                }

                unsigned int NewCountDir = CountDir + 1 - (i + 1 == X);
                if(NewCountDir < Dist[Index])
                {
                    Dist[Index] = NewCountDir;
                    unsigned int Pack = Packet(NewCountDir, static_cast<unsigned int>(DRow), static_cast<unsigned int>(DCol));
                    MinHeap.push(Pack);
                }
            }
        }

        return -1;
    }

private:
    unsigned int Packet(unsigned int CountDir, unsigned int Row, unsigned int Col)
    {
        return (CountDir << 16) + (Row << 8) + Col;
    }

    array<int, 3> Receive(unsigned int ReceivePacket)
    {
        array<int, 3> Buffer;
        Buffer[0] = ReceivePacket >> 16;
        Buffer[1] = (ReceivePacket >> 8) & 255;
        Buffer[2] = ReceivePacket & 255;
        return Buffer;
    }

    unsigned int IndexTo1D(int Row, int Col, int ColSize)
    {
        return Row * ColSize + Col;
    }

    bool InBoundary(int Row, int Col)
    {
        if(Row >= 0 && Row < Rows && Col >= 0 && Col < Cols)
            return true;

        return false;
    }
};