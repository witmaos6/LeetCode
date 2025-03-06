class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid)
    {
        const int N = static_cast<int>(grid.size());
        vector<bool> Table(N * N + 1);
        int ExpectedTotal = pow(N, 2) * (pow(N, 2) + 1) / 2;
        int Total = 0;
        int TwiceNum = 0;
        for(vector<int>& Row : grid)
        {
            for(int& Num : Row)
            {
                if(Table[Num])
                {
                    TwiceNum = Num;
                }
                Total += Num;
                Table[Num] = true;
            }
        }

        vector<int> Result = {TwiceNum, TwiceNum + ExpectedTotal - Total};
        return Result;
    }
};