class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        const int N = static_cast<int>(grid.size());
        if(N == 1)
        {
            return grid.front().front();
        }
        
        for(int i = 1; i < N; i++)
        {
            auto[Min1, Min2] = GetMinTwoInt(grid[i - 1]);
            
            for(int j = 0; j < N; j++)
            {
                if(grid[i - 1][j] == Min1)
                {
                    grid[i][j] += Min2;
                }
                else
                {
                    grid[i][j] += Min1;
                }
            }
        }
        
        return *min_element(grid.back().begin(), grid.back().end());
    }
    
private:
    pair<int, int> GetMinTwoInt(vector<int>& Arr)
    {
        pair<int, int> Result = {INT_MAX, INT_MAX};
        
        for(int Num : Arr)
        {
            if(Num < Result.first)
            {
                Result.second = exchange(Result.first, Num);
            }
            else if(Num < Result.second)
            {
                Result.second = Num;
            }
        }
        return Result;
    }
};

