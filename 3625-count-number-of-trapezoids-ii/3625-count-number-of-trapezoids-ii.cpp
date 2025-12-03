class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points)
    {
        unordered_map<int, unordered_map<int, int>> T, V;

        const int N = static_cast<int>(points.size());
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                int DX = points[j][0] - points[i][0];
                int DY = points[j][1] - points[i][1];

                if(DX < 0 || (DX == 0 && DY < 0))
                {
                    DX = -DX;
                    DY = -DY;
                }

                int G = gcd(DX, abs(DY));

                int SX = DX / G;
                int SY = DY / G;

                int Des = SX * points[i][1] - SY * points[i][0];

                int Key1 = (SX << 12) | (SY + 2000);
                int Key2 = (DX << 12) | (DY + 2000);

                ++T[Key1][Des];
                ++V[Key2][Des];
            }
        }

        return Count(T) - Count(V) / 2;
    }

private:
    int Count(unordered_map<int, unordered_map<int, int>>& Table)
    {
        long long Result = 0;

        for(auto& [K1, Inner] : Table)
        {
            long long Sum = 0;

            for(auto& [K2, Val] : Inner)
            {
                Sum += Val;
            }

            for(auto& [K2, Val] : Inner)
            {
                Sum -= Val;
                Result += Val * Sum;
            }
        }
        return Result;
    }
};