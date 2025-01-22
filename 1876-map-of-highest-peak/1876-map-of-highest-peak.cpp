class Solution {
    const int Land = 0;
    const int Water = 1;
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        const int Rows = static_cast<int>(isWater.size());
        const int Cols = static_cast<int>(isWater[0].size());

        vector<vector<int>> Heights(Rows, vector<int>(Cols, -1));
        queue<int> BFS;

        for(int Row = 0; Row < Rows; Row++)
        {
            for(int Col = 0; Col < Cols; Col++)
            {
                if(isWater[Row][Col] == Water)
                {
                    Heights[Row][Col] = 0;
                    BFS.push(Row * Cols + Col);
                }
            }
        }

        array<int, 5> Dir = {-1,0,1,0,-1};

        while(!BFS.empty())
        {
            int Row = BFS.front() / Cols;
            int Col = BFS.front() % Cols;
            BFS.pop();

            for(int i = 0; i < 4; i++)
            {
                int DRow = Row + Dir[i];
                int DCol = Col + Dir[i + 1];

                if(DRow >= 0 && DRow < Rows && DCol >= 0 && DCol < Cols && Heights[DRow][DCol] == -1)
                {
                    Heights[DRow][DCol] = Heights[Row][Col] + 1;
                    BFS.push(DRow * Cols + DCol);
                }
            }
        }
        return Heights;
    }
};