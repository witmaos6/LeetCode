class Solution {
public:
    double separateSquares(vector<vector<int>>& squares)
    {
        double Left = 2e9;
        double Right = 0;
        double TotalArea = 0;

        for(vector<int>& Square : squares)
        {
            double Y = Square[1];
            double L = Square[2];

            TotalArea += L * L;
            Left = min(Left, Y);
            Right = max(Right, Y + L);
        }

        double Target = TotalArea / 2.0;

        for(int i = 0; i < 100; i++)
        {
            double Mid = Left + (Right - Left) / 2.0;
            double CurrArea = 0;

            for(vector<int>& Square : squares)
            {
                double Y = Square[1];
                double L = Square[2];

                double Below = max(0.0, min(L, Mid - Y));
                CurrArea += Below * L;
            }

            if(CurrArea < Target)
            {
                Left = Mid;
            }
            else
            {
                Right = Mid;
            }
        }

        return Right;
    }
};