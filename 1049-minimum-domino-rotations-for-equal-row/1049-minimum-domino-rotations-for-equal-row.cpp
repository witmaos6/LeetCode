class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        const int N = static_cast<int>(tops.size());
        int Result = INT_MAX;
        for(int Num = 1; Num <= 6; Num++)
        {
            int TopSwap = 0;
            int BottomSwap = 0;

            for(int i = 0; i < N; i++)
            {
                if(tops[i] != Num && bottoms[i] != Num)
                {
                    TopSwap = INT_MAX;
                    BottomSwap = INT_MAX;
                    break;
                }
                if(tops[i] != Num)
                {
                    TopSwap++;
                }
                if(bottoms[i] != Num)
                {
                    BottomSwap++;
                }
            }
            int Temp = min(TopSwap, BottomSwap);
            Result = min(Result, Temp);
        }

        return (Result == INT_MAX) ? -1 : Result;
    }
};