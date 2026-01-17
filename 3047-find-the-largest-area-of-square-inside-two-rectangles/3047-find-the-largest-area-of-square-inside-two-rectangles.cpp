class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight)
    {
        const int N = static_cast<int>(bottomLeft.size());
        int MaxLen = 0;

        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                int MinX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int MaxX = min(topRight[i][0], topRight[j][0]);
                int MinY = max(bottomLeft[i][1], bottomLeft[j][1]);
                int MaxY = min(topRight[i][1], topRight[j][1]);

                if(MinX < MaxX && MinY < MaxY)
                {
                    int Len = min(MaxX - MinX, MaxY - MinY);
                    MaxLen = max(MaxLen, Len);
                }
            }
        }
        return 1LL * MaxLen * MaxLen;
    }
};