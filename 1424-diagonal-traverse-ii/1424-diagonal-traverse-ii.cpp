class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums)
    {
        const size_t RowSize = nums.size();
        size_t MaxColSize = 0;
        
        for(size_t i = 0; i < RowSize; i++)
        {
            MaxColSize = max(MaxColSize, nums[i].size());
        }
        
        vector<vector<int>> Table(RowSize + MaxColSize);
        for(size_t Row = 0; Row < RowSize; Row++)
        {
            for(size_t Col = 0; Col < nums[Row].size(); Col++)
            {
                Table[Row + Col].push_back(nums[Row][Col]);
            }
        }
        
        vector<int> Result;
        for(size_t i = 0; i < RowSize + MaxColSize; i++)
        {
            for(int j = Table[i].size() - 1; j >= 0; j--)
            {
                Result.push_back(Table[i][j]);
            }
        }
        
        return Result;
    }
};