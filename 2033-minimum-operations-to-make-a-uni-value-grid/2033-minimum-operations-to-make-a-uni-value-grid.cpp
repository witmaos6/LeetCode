class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x)
    {
        vector<int> Nums;
        int NumsSize = static_cast<int>(grid.size() * grid[0].size());
        Nums.reserve(NumsSize);
        
        for(vector<int>& Row : grid)
        {
            for(int& Col : Row)
            {
                Nums.push_back(Col);
            }
        }
        sort(Nums.begin(), Nums.end());
        
        int Target = Nums[NumsSize >> 1];
        int Result = 0;
        
        for(int& Num : Nums)
        {
            int Temp = abs(Num - Target);
            if(Temp % x != 0)
            {
                return -1;
            }
            else
            {
                Result += Temp / x;
            }
        }
        
        return Result;
    }
};