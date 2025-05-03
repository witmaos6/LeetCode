class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        const int N = static_cast<int>(tops.size());
        int Result = INT_MAX;
        for(int Num = 1; Num <= 6; Num++)
        {
            int TopsCount = 0;
            int BottomsCount = 0;
            int BothCount = 0;
            bool Impossible = false;

            for(int i = 0; i < N; i++)
            {
                if(tops[i] != Num && bottoms[i] != Num)
                {
                    Impossible = true;
                    break;
                }
                if(tops[i] == Num && bottoms[i] == Num)
                {
                    BothCount++;
                }
                if(tops[i] == Num)
                {
                    TopsCount++;
                }
                if(bottoms[i] == Num)
                {
                    BottomsCount++;
                }
            }

            if(!Impossible)
            {
                Result = min(TopsCount - BothCount, BottomsCount - BothCount);
            }
        }

        return (Result == INT_MAX) ? -1 : Result;
    }
};