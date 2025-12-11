class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings)
    {
        vector<int> MinX(n + 1, n + 1);
        vector<int> MaxX(n + 1, 0);
        vector<int> MinY(n + 1, n + 1);
        vector<int> MaxY(n + 1, 0);

        for(vector<int>& B : buildings)
        {
            int X = B[0];
            int Y = B[1];

            MinX[Y] = min(MinX[Y], X);
            MaxX[Y] = max(MaxX[Y], X);
            MinY[X] = min(MinY[X], Y);
            MaxY[X] = max(MaxY[X], Y);
        }

        int Count = 0;
        for(vector<int>& B : buildings)
        {
            int X = B[0];
            int Y = B[1];
            if(MinX[Y] < X && X < MaxX[Y] && MinY[X] < Y && Y < MaxY[X])
            {
                Count++;
            }
        }
        return Count;
    }
};