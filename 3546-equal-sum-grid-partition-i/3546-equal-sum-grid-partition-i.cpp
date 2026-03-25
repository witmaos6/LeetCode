class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid)
    {
        const int Rows = grid.size();
        const int Cols = grid[0].size();

        vector<long long> ColSums;
        ColSums.reserve(Rows);
        for(int i = 0; i < Rows; i++)
        {
            long long Sum = 0;
            for(int j = 0; j < Cols; j++)
            {
                Sum += grid[i][j];
            }
            ColSums.push_back(Sum);
        }

        if(EqualPrefSuff(ColSums))
            return true;

        vector<long long> RowSums;
        RowSums.reserve(Cols);
        for(int i = 0; i < Cols; i++)
        {
            long long Sum = 0;
            for(int j = 0; j < Rows; j++)
            {
                Sum += grid[j][i];
            }
            RowSums.push_back(Sum);
        }

        return EqualPrefSuff(RowSums);
    }
private:
    bool EqualPrefSuff(vector<long long>& Sums)
    {
        int N = Sums.size();
        long long Pref = 0;
        long long Suff = 0;
        for(int i = 0; i < N; i++)
        {
            Suff += Sums[i];
        }
        for(int i = 0; i < N; i++)
        {
            Pref += Sums[i];
            Suff -= Sums[i];
            if(Pref == Suff)
                return true;
        }
        return false;
    }
};